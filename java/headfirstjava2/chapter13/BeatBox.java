import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.sound.midi.*;
import java.util.*;

public class BeatBox {
  JPanel mainPanel;
  // we store the checkboxes in an ArrayList
  ArrayList<JCheckBox> checkboxList;
  Sequencer sequencer;
  Sequence sequence;
  Track track;
  JFrame theFrame;

  // These are the names of the instruments, as a String array,
  // for building the GUI labels (on each row)
  String[] instrumentNames = {
    "Bass Drum", "Closed Hi-Hat", "Open Hi-Hat", "Acoustic Snare",
    "Crash Cymbal", "Hand Clap", "High Tom", "Hi Bongo", "Maracas",
    "Whistle", "Low Conga", "Cowbell", "Vibraslap", "Low-mid Tom",
    "High Agogo", "Open Hi Conga",
  };

  // these represent the actual drum 'keys'. The drum channel is like
  // a piano, except each 'key' on the piano is a different drum.
  // so the number '35' is the key for the Bass drum, 42 is Closed
  // Hi-Hat, etc.
  int[] instruments = {
    35, 42, 46, 38,
    49, 39, 50, 60, 70,
    72, 64, 56, 58, 47,
    67, 63,
  };

  public static void main(String[] args) {
    BeatBox bb = new BeatBox();
    bb.buildGUI();
  }

  public void buildGUI() {
    theFrame = new JFrame("Cyber BeatBox");
    theFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    BorderLayout layout = new BorderLayout();
    JPanel background = new JPanel(layout);
    // An 'empty border' gives us a margin between the edges of the panel
    // and where the components are placed purely aesthetic.
    background.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

    checkboxList = new ArrayList<JCheckBox>();
    Box buttonBox = new Box(BoxLayout.Y_AXIS);

    JButton start = new JButton("Start");
    start.addActionListener(new MyStartListener());
    buttonBox.add(start);

    JButton stop = new JButton("Stop");
    stop.addActionListener(new MyStopListener());
    buttonBox.add(stop);

    JButton upTempo = new JButton("Tempo Up");
    upTempo.addActionListener(new MyUpTempoListener());
    buttonBox.add(upTempo);

    JButton downTempo = new JButton("Tempo Down");
    downTempo.addActionListener(new MyDownTempoListener());
    buttonBox.add(downTempo);

    Box nameBox = new Box(BoxLayout.Y_AXIS);
    for (int i = 0; i < 16; i++) {
      nameBox.add(new Label(instrumentNames[i]));
    }

    background.add(BorderLayout.EAST, buttonBox);
    background.add(BorderLayout.WEST, nameBox);

    theFrame.getContentPane().add(background);

    GridLayout grid = new GridLayout(16, 16);
    grid.setVgap(1);
    grid.setHgap(2);
    mainPanel = new JPanel(grid);
    background.add(BorderLayout.CENTER, mainPanel);

    // make the checkboxes, set them to 'false' and add them to
    // the ArrayList and to the GUI panel
    for (int i = 0; i < 256; i++) {
      JCheckBox c = new JCheckBox();
      c.setSelected(false);
      checkboxList.add(c);
      mainPanel.add(c);
    }

    setUpMidi();

    theFrame.setBounds(50, 50, 300, 300);
    theFrame.pack();
    theFrame.setVisible(true);
  }

  public void setUpMidi() {
    try {
      sequencer = MidiSystem.getSequencer();
      sequencer.open();
      sequence = new Sequence(Sequence.PPQ, 4);
      track = sequence.createTrack();
      sequencer.setTempoInBPM(120);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  // This is where it all happens! Where we turn checkbox state
  // into MIDI events, and add them to the Track
  public void buildTrackAndStart() {
    int[] trackList = null;

    // get rid of the old track, make a fresh one
    sequence.deleteTrack(track);
    track = sequence.createTrack();

    // do this for each of the 16 ROWS
    for (int i = 0; i < 16; i++) {
      trackList = new int[16];
      // set the 'key', that represents which instrument this is
      // The instrument array holds the actual MIDI numbers
      int key = instruments[i];
      // do this for each of the BEATS for this row
      for (int j = 0; j < 16; j++) {
        JCheckBox jc = (JCheckBox) checkboxList.get(j+16*i);
        // is the checkbox at this beat selected?
        if (jc.isSelected()) {
          trackList[j] = key;
        } else {
          trackList[j] = 0;
        }
      } // close inner loop

      // For this instrument, and for all 16 beats, make events and
      // add them to the track
      makeTracks(trackList);
      track.add(makeEvent(176, 1, 127, 0, 16));
    } // close outer loop

    // we always want to make sure that there IS an event at beat 16
    // (it goes 0 to 15). Otherwise, the BeatBox might not go the full
    // 16 beats before it starts over.
    track.add(makeEvent(192, 9, 1, 0, 15));
    try {
      sequencer.setSequence(sequence);
      sequencer.setLoopCount(sequencer.LOOP_CONTINUOUSLY);
      sequencer.start();
      sequencer.setTempoInBPM(120);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public class MyStartListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      buildTrackAndStart();
    }
  } // close inner class

  public class MyStopListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      sequencer.stop();
    }
  } // close inner class

  public class MyUpTempoListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      float tempoFactor = sequencer.getTempoFactor();
      sequencer.setTempoFactor((float)(tempoFactor*1.03));
    }
  } // close inner class

  public class MyDownTempoListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      float tempoFactor = sequencer.getTempoFactor();
      sequencer.setTempoFactor((float)(tempoFactor*0.97));
    }
  } // close inner class

  public void makeTracks(int[] list) {
    for (int i = 0; i < 16; i++) {
      int key = list[i];

      if (key != 0) {
        // make the NOTE ON and NOT OFF events, and add them to the Track
        track.add(makeEvent(144, 9, key, 100, i));
        track.add(makeEvent(128, 9, key, 100, i+1));
      }
    }
  }

  public MidiEvent makeEvent(int comd, int chan, int one, int two, int tick) {
    MidiEvent event = null;
    try {
      ShortMessage a = new ShortMessage();
      a.setMessage(comd, chan, one, two);
      event = new MidiEvent(a, tick);
    } catch (Exception e) {
      e.printStackTrace();
    }

    return event;
  }
}

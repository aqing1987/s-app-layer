/*
 * Version 3: drawing graphics in time with the music
 */
import javax.sound.midi.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;

// we need to listen for ControllerEvents, so we implements the listener
// interface
public class MiniMusicPlayer3 {

  static JFrame f = new JFrame("My first music video");
  static MyDrawPanel ml;

  public static void main(String[] args) {
    MiniMusicPlayer3 mini = new MiniMusicPlayer3();
    mini.go();
  }

  public void setUpGui() {
    ml = new MyDrawPanel();
    f.setContentPane(ml);
    f.setBounds(30, 30, 300, 300);
    f.setVisible(true);
  }

  public void go() {
    setUpGui();

    try {
      // make and open a sequencer
      Sequencer sequencer = MidiSystem.getSequencer();
      sequencer.open();

      // register for events with the sequencer. The event registration
      // method takes the listener AND an int array representing the list
      // of ControllerEvents you want. We want only one event, #127
      int[] eventsIWant = {127};
      sequencer.addControllerEventListener(ml, eventsIWant);

      // make a sequence and a track
      Sequence seq = new Sequence(Sequence.PPQ, 4);
      Track track = seq.createTrack();

      // make a bunch of events to make the notes keep going up
      // (from piano note5 to piano note 61)
      int r = 0;
      for (int i = 0; i < 60; i += 4) {
        r = (int) ((Math.random() * 50) + 1);
        // NOTE ON (144)
        track.add(makeEvent(144, 1, r, 100, i));

        // insert our OWN ControllerEvent
        // 176 says the event type is ControllerEvent, 127 is the event number
        // This event will do NOTHING. We put it in JUST so that we can
        // get an event each time a note is played.
        track.add(makeEvent(176, 1, 127, 0, i));

        // NOTE OFF (128)
        track.add(makeEvent(128, 1, r, 100, i+2));
      }

      sequencer.setSequence(seq);
      sequencer.setTempoInBPM(220);
      sequencer.start();
    } catch (Exception ex) {
      ex.printStackTrace();
    }
  }

  // the four arguments for the message
  // the event 'tick' for WHEN this message should happen
  public static MidiEvent makeEvent(int comd, int chan, int one,
                                    int two, int tick) {
    MidiEvent event = null;
    try {
      ShortMessage a = new ShortMessage();
      a.setMessage(comd, chan, one, two);
      event = new MidiEvent(a, tick);
    } catch (Exception e) {}

    return event;
  }

  // inner class
  class MyDrawPanel extends JPanel implements ControllerEventListener {
    boolean msg = false;

    // Interface ControllerEventListener
    // Invoked when a Sequencer has encountered and processed a
    // control-change event of interest to this listener.
    public void controlChange(ShortMessage event) {
      msg = true;
      repaint();
    }

    // repaint will invoke this api
    public void paintComponent(Graphics g) {
      if (msg) {
        Graphics2D g2 = (Graphics2D) g;

        int r = (int) (Math.random() * 250);
        int gr = (int) (Math.random() * 250);
        int b = (int) (Math.random() * 250);
        g.setColor(new Color(r, gr, b));

        int height = (int) ((Math.random() * 120) + 10);
        int width = (int) ((Math.random() * 120) + 10);
        int x = (int) ((Math.random() * 40) + 10);
        int y = (int) ((Math.random() * 40) + 10);
        g.fillRect(x, y, height, width);

        msg = false;
      }
    }
  }
}
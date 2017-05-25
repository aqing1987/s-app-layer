/*
 * Version 2: register and get ControllerEvents
 */
import javax.sound.midi.*;

// we need to listen for ControllerEvents, so we implements the listener
// interface
public class MiniMusicPlayer2 implements ControllerEventListener {
  public static void main(String[] args) {
    MiniMusicPlayer2 mini = new MiniMusicPlayer2();
    mini.go();
  }

  public void go() {
    try {
      // make and open a sequencer
      Sequencer sequencer = MidiSystem.getSequencer();
      sequencer.open();

      // register for events with the sequencer. The event registration
      // method takes the listener AND an int array representing the list
      // of ControllerEvents you want. We want only one event, #127
      int[] eventsIWant = {127};
      sequencer.addControllerEventListener(this, eventsIWant);

      // make a sequence and a track
      Sequence seq = new Sequence(Sequence.PPQ, 4);
      Track track = seq.createTrack();

      // make a bunch of events to make the notes keep going up
      // (from piano note5 to piano note 61)
      for (int i = 5; i < 61; i += 4) {
        // NOTE ON (144)
        track.add(makeEvent(144, 1, i, 100, i));

        // insert our OWN ControllerEvent
        // 176 says the event type is ControllerEvent, 127 is the event number
        // This event will do NOTHING. We put it in JUST so that we can
        // get an event each time a note is played.
        track.add(makeEvent(176, 1, 127, 0, i));

        // NOTE OFF (128)
        track.add(makeEvent(128, 1, i, 100, i+2));
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

  // Interface ControllerEventListener
  // Invoked when a Sequencer has encountered and processed a
  // control-change event of interest to this listener.
  public void controlChange(ShortMessage event) {
    System.out.println("la");
  }
}
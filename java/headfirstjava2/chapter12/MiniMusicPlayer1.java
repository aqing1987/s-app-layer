import javax.sound.midi.*;

public class MiniMusicPlayer1 {
  public static void main(String[] args) {
    try {
      // make and open a sequencer
      Sequencer sequencer = MidiSystem.getSequencer();
      sequencer.open();

      // make a sequence and a track
      Sequence seq = new Sequence(Sequence.PPQ, 4);
      Track track = seq.createTrack();

      // make a bunch of events to make the notes keep going up
      // (from piano note5 to piano note 61)
      for (int i = 5; i < 61; i += 4) {
        // NOTE ON (144)
        track.add(makeEvent(144, 1, i, 100, i));
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
}
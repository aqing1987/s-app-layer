import javax.sound.midi.*;

public class MiniMiniMusicApp {
  public static void main(String[] args) {
    MiniMiniMusicApp mini = new MiniMiniMusicApp();
    mini.play();
  }

  public void play() {
    try {
      // get a sequencer and open it
      Sequencer player = MidiSystem.getSequencer();
      player.open();

      // make a new sequence
      Sequence seq = new Sequence(Sequence.PPQ, 4);

      // get a new Track from the sequence
      // the track lives in the Sequence, and the MIDI data lives in
      // the Track
      Track t = seq.createTrack();

      // fill the track with midievents
      // the Message says what to do, and the MidiEvent says when to do.
      ShortMessage a = new ShortMessage();
      // 144 - NOTE ON, 1 - channel 1, 50 - note to play, 100 - velocity
      a.setMessage(144, 1, 50, 100);
      MidiEvent noteOn = new MidiEvent(a, 1); // trigger a at the first beat
      t.add(noteOn);

      ShortMessage first = new ShortMessage();
      // 192 - change instrument message
      first.setMessage(192, 1, 102, 100);
      MidiEvent cc = new MidiEvent(a, 2); // trigger a at the first beat
      t.add(cc);

      ShortMessage b = new ShortMessage();
      // 128 - note off, 1 - channel, 100 - note to play,
      a.setMessage(128, 1, 100, 100);
      MidiEvent noteOff = new MidiEvent(b, 3);
      t.add(noteOff);

      // give the sequence to the sequencer (like putting CD in the CD player)
      player.setSequence(seq);

      // start() the sequencer (like pushing PLAY)
      player.start();
    } catch (Exception ex) {
      ex.printStackTrace();
    }
  }
}
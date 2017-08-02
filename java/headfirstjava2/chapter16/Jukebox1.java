import java.util.*;
import java.io.*;

public class Jukebox1 {
  // we'll store the song titles in an ArrayList of Strings
  ArrayList<String> songList = new ArrayList<String>();

  public static void main(String[] args) {
    new Jukebox1().go();
  }

  public void go() {
    getSongs();
    System.out.println(songList);

    // sort in alphabetical order before print
    Collections.sort(songList);
    System.out.println(songList);
  }

  void getSongs() {
    try {
      File file = new File("SongList.txt");
      BufferedReader reader = new BufferedReader(new FileReader(file));
      String line = null;
      while ((line = reader.readLine()) != null) {
        addSong(line);
      }
    } catch (Exception ex) {
      ex.printStackTrace();
    }
  }

  void addSong(String lineToParse) {
    String[] tokens = lineToParse.split("/");
    // only add the song title
    songList.add(tokens[0]);
  }
}
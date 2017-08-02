/**
 * Created by rex on 7/27/17.
 */
import java.util.*;
import java.io.*;

public class Jukebox8 {

  ArrayList<Song> songList = new ArrayList<Song>();

  public static void main(String[] args) {
    new Jukebox8().go();
  }

  public void go() {
    getSongs();
    System.out.println(songList);
    Collections.sort(songList);
    System.out.println(songList);

    // TreeSet is similar to HashSet in that it prevents duplicates. But it also
    // keeps the list sorted.
    // instantiate a TreeSet intead of HashSet. Calling the no-arg TreeSet
    // constructor means the set will use the Song object's compareTo() method
    // for the sort, we could have passed in a Comparator
    TreeSet<Song> songSet = new TreeSet<Song>();
    songSet.addAll(songList);
    System.out.println(songSet);
  }

  void getSongs() {
    try {
      File file = new File("SongListMore.txt");
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
    Song nextSong = new Song(tokens[0], tokens[1], tokens[2], tokens[3]);
    songList.add(nextSong);
  }
}

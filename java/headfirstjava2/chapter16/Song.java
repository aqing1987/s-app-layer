public class Song implements Comparable<Song> {
  // four instance variables for the four song attributes in the file
  String title;
  String artist;
  String rating;
  String bpm;

  // The HashSet sends it another Song
  public boolean equals(Object aSong) {
    Song s = (Song) aSong;
    return getTitle().equals(s.getTitle());
  }

  // The String class has an overridden hasCode() method
  public int hashCode() {
    return title.hashCode();
  }

  public int compareTo(Song s) {
    return title.compareTo(s.getTitle());
  }

  Song(String t, String a, String r, String b) {
    title = t;
    artist = a;
    rating = r;
    bpm = b;
  }

  public String getTitle() {
    return title;
  }

  public String getArtist() {
    return artist;
  }

  public String getRating() {
    return rating;
  }

  public String getBpm() {
    return bpm;
  }

  // we override toStirng() because when you do a System.out.println(aSongObject)
  // we want to see the title
  public String toString() {
    return title;
  }
}

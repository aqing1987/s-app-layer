import java.io.*;

class WriteAFile {
  public static void main(String[] args) {
    // ALL the I/O stuff must be in a try/catch, everything
    // can throw an IOException
    try {
      FileWriter writer = new FileWriter("Foo.txt");
      writer.write("hello foo!\n");
      writer.close();
    } catch (IOException ex) {
      ex.printStackTrace();
    }
  }
}
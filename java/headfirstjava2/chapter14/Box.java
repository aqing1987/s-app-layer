// Serializable is in the java.io package
import java.io.*;

// No methods to implement, but when you say "implements Serializable",
// it says to the JVM, "it's OK to serialize objects of this type"
public class Box implements Serializable {
  // these two values will be saved
  private int width;
  private int height;

  public void setWidth(int w) {
    width = w;
  }

  public void setHeight(int h) {
    height = h;
  }

  public static void main(String[] args) {
    Box myBox = new Box();
    myBox.setWidth(50);
    myBox.setHeight(20);

    // I/O operations can throw exception
    try {
      FileOutputStream fs = new FileOutputStream("foo.ser");
      // make an ObjectOutputStream chained to the connection stream
      ObjectOutputStream os = new ObjectOutputStream(fs);
      os.writeObject(myBox);
      os.close();
    } catch (Exception ex) {
      ex.printStackTrace();
    }
  }
}
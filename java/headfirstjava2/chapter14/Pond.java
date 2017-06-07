import java.io.*;

public class Pond implements Serializable {
  // one instance variable, a Duck
  private Duck duck = new Duck();

  public static void main(String[] args) {
    Pond myPond = new Pond();
    try {
      FileOutputStream fs = new FileOutputStream("pond.ser");
      ObjectOutputStream os = new ObjectOutputStream(fs);

      // when you serialize myPond, its Duck instance variable
      // automatically gets serialized.
      os.writeObject(myPond);
      os.close();
    } catch (Exception ex) {
      ex.printStackTrace();
    }
  }
}

// Duck is not serializable.
class Duck {}
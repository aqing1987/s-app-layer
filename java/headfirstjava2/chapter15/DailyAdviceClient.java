/**
 * This program makes a Socket, makes a BufferedReader, and reads
 * a single line from the server application(port 4242)
 */
import java.io.*;
import java.net.*; // class Socket is in java.net

public class DailyAdviceClient {
  public static void main(String[] args) {
    DailyAdviceClient client = new DailyAdviceClient();
    client.go();
  }

  public void go() {
    try {
      // make a Socket connection to whatever is running on port 4242, on the
      // same host this code is running on
      Socket s = new Socket("127.0.0.1", 4242);

      // chain a BufferedReader to an InputStreamReader to the input stream from
      // the Socket
      InputStreamReader streamReader = new InputStreamReader(s.getInputStream());
      BufferedReader reader = new BufferedReader(streamReader);

      String advice = reader.readLine();
      System.out.println("Today you should: " + advice);

      // closes all the streams
      reader.close();

    } catch (IOException ex) {
      ex.printStackTrace();
    }
  }
}

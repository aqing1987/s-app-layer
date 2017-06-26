/**
 * This program makes a ServerSocket and waits for client requests.
 * When it gets a client request, the server makes a new Socket connection
 * to that client. The server makes a PrintWriter and sends a message to
 * the client.
 */
import java.io.*;
import java.net.*;

public class DailyAdviceServer {
  // daily advice comes from this array
  String[] adviceList = {
          "Take smaller bites",
          "Go for the tight jeans. No they do NOT make you look fat.",
          "One word: inappropriate",
          "Just for today, be honest. Tell your boss what you *really* think",
          "You might want to rethink that haircut.",
  };

  public static void main(String[] args) {
    DailyAdviceServer server = new DailyAdviceServer();
    server.go();
  }

  public void go() {

    try {
      // ServerSocket makes this server application 'listen' for client requests
      // on port 4242 on the machine this code is running on
      ServerSocket serverSock = new ServerSocket(4242);

      // The server goes into a permanent loop, waiting for client requests
      while (true) {
        // the accept method blocks until a request comes in, and then the
        // method returns a Socket for communicating with the client
        Socket sock = serverSock.accept();

        PrintWriter writer = new PrintWriter(sock.getOutputStream());
        String advice = getAdvice();
        writer.println(advice);
        writer.close();
        System.out.println(advice);
      }

    } catch (IOException ex) {
      ex.printStackTrace();
    }
  }

  private String getAdvice() {
    int random = (int) (Math.random() * adviceList.length);
    return adviceList[random];
  }
}

import java.io.*;
import java.net.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleChatClient {
  JTextArea incoming;
  JTextField outgoing;
  BufferedReader reader;
  PrintWriter writer;
  Socket sock;

  public static void main(String[] args) {
    SimpleChatClient client = new SimpleChatClient();
    client.go();
  }

  public void go() {
    JFrame frame = new JFrame("Ludicrously Simple Chat Client");
    JPanel mainPanel = new JPanel();

    incoming = new JTextArea("");
    incoming.setLineWrap(true);
    incoming.setWrapStyleWord(true);
    incoming.setEditable(false);

    JScrollPane qScroller = new JScrollPane(incoming);
    qScroller.setVerticalScrollBarPolicy(
            ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
    qScroller.setHorizontalScrollBarPolicy(
            ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);

    outgoing = new JTextField(20);

    JButton sendButton = new JButton("Send");
    sendButton.addActionListener(new SendButtonListener());

    //mainPanel.add(qScroller);
    mainPanel.add(outgoing);
    mainPanel.add(sendButton);

    setUpNetworking();

    frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    frame.getContentPane().add(BorderLayout.CENTER, qScroller);
    frame.getContentPane().add(BorderLayout.SOUTH, mainPanel);
    frame.setSize(400, 500);
    frame.setVisible(true);

    Thread readerThread = new Thread(new IncomingReader());
    readerThread.start();
  }

  private void setUpNetworking() {
    try {
      sock = new Socket("127.0.0.1", 5000);
      InputStreamReader streamReader = new InputStreamReader(sock.getInputStream());
      reader = new BufferedReader(streamReader);
      writer = new PrintWriter(sock.getOutputStream());
      System.out.println("networking established");
    } catch (IOException ex) {
      ex.printStackTrace();
    }
  }

  // when the user clicks the send button, sends the contents of
  // the text field to the server
  public class SendButtonListener implements ActionListener {
    public void actionPerformed(ActionEvent ev) {
      try {
        writer.println(outgoing.getText());
        writer.flush();
      } catch (Exception ex) {
        ex.printStackTrace();
      }

      outgoing.setText("");
      outgoing.requestFocus();
    }
  }

  // the thread's job is to read from the server's socket stream,
  // displaying any incoming messages in the scrolling text area.
  public class IncomingReader implements Runnable {
    public void run() {
      String message;
      try {
        while ((message = reader.readLine()) != null) {
          System.out.println("read: " + message);
          incoming.append(message + "\n");
        }
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    }
  }
}



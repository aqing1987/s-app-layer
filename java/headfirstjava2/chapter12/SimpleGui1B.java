import javax.swing.*;
import java.awt.event.*;

public class SimpleGui1B implements ActionListener {
  JButton button;

  public static void main(String[] args) {
    SimpleGui1B gui = new SimpleGui1B();
    gui.go();
  }

  public void go() {
    JFrame frame = new JFrame();
    button = new JButton("click me");

    // add me to your list of listeners
    // the argument you pass MUST be an object from a class that
    // implements ActionListener
    button.addActionListener(this);

    frame.getContentPane().add(button);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(300, 300);
    frame.setVisible(true);
  }

  // implement the ActionListener interface's actionPerformed() method.
  // This is the actual event-handling method.
  public void actionPerformed(ActionEvent event) {
    button.setText("I've been clicked!");
  }
}
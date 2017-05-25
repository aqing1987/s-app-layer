import javax.swing.*;

public class SimpleGui1 {
  public static void main(String[] args) {
    // make a frame
    JFrame frame = new JFrame();

    // make a button
    JButton button = new JButton("click me");

    // makes the program quit as soon as you close the window
    // If you leave this out it will just sit there on the screen forever
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    // add the button to the frame's content pane
    frame.getContentPane().add(button);

    // give the frame a size, in pixels
    frame.setSize(300, 300);

    // make it visible, if you forget this step, you won't see anything
    // when you run this code
    frame.setVisible(true);
  }
}
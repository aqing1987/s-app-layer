/*
 * BorderLayout cares about five regions:
 *  east, west, north, south, and center
 */
import javax.swing.*;
import java.awt.*; // BorderLayout is in java.awt package

public class Button1 {
  public static void main(String[] args) {
    Button1 gui = new Button1();
    //gui.go();
    gui.go1();
  }

  public void go() {
    JFrame frame = new JFrame();
    if (false) {
      JButton button = new JButton("click me");
      frame.getContentPane().add(BorderLayout.EAST, button);
    }

    if (false) {
      JButton button = new JButton("click liek you mean it");
      frame.getContentPane().add(BorderLayout.EAST, button);
    }

    if (false) {
      JButton button = new JButton("There is no spoon...");
      frame.getContentPane().add(BorderLayout.NORTH, button);
    }

    // a bigger font will force the frame to allocate more space
    // for the button's height
    if (true) {
      JButton button = new JButton("Click This!");
      Font bigFont = new Font("serif", Font.BOLD, 28);
      button.setFont(bigFont);
      frame.getContentPane().add(BorderLayout.NORTH, button);
    }
    frame.setSize(300, 300);
    frame.setVisible(true);
  }

  // components in the center get whatever space is left over,
  // based on the frame dimensions.
  public void go1() {
    JFrame frame = new JFrame();

    JButton east = new JButton("East");
    JButton west = new JButton("West");
    JButton north = new JButton("North");
    JButton south = new JButton("South");
    JButton center = new JButton("Center");

    frame.getContentPane().add(BorderLayout.EAST, east);
    frame.getContentPane().add(BorderLayout.WEST, west);
    frame.getContentPane().add(BorderLayout.NORTH, north);
    frame.getContentPane().add(BorderLayout.SOUTH, south);
    frame.getContentPane().add(BorderLayout.CENTER, center);

    frame.setSize(300, 300);
    frame.setVisible(true);
  }
}


/*
 * FlowLayout cares about the flow of the components:
 *   left to right, top to bottom, in the order they were added.
 */

import javax.swing.*;
import java.awt.*;

public class Panel1 {
  public static void main(String[] args) {
    Panel1 gui = new Panel1();
    gui.go();
  }

  public void go() {
    JFrame frame = new JFrame();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JPanel panel = new JPanel();
    panel.setBackground(Color.darkGray);

    // add the button to the panel and add the panel to the frame.
    // The panel's layout manager(flow) controls the button, and the frame's
    // layout manager(border) controls the panel
    JButton button = new JButton("shock me");
    panel.add(button);

    if (true) {
      // add another button
      JButton btn2 = new JButton("bliss");
      panel.add(btn2);
    }

    frame.getContentPane().add(BorderLayout.EAST, panel);
    frame.setSize(250, 200);
    frame.setVisible(true);
  }
}
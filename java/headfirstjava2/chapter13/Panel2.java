/*
 * Unlike FlowLayout, BoxLayout can force a 'new line' to make the
 * components wrap to the next line, even if there's room for them
 * to fit horizontally.
 */

import javax.swing.*;
import java.awt.*;

public class Panel2 {
  public static void main(String[] args) {
    Panel2 gui = new Panel2();
    gui.go();
  }

  public void go() {
    JFrame frame = new JFrame();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JPanel panel = new JPanel();
    panel.setBackground(Color.darkGray);

    // change the layout manager to be a new instance of BoxLayout
    // use Y_AXIS for a vertical stack
    panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

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
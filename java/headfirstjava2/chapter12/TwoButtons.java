import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

// the main GUI class doesn't implement ActionListener now
public class TwoButtons {
  JFrame frame;
  JLabel label;

  public static void main(String[] args) {
    TwoButtons gui = new TwoButtons();
    gui.go();
  }

  public void go() {
    frame = new JFrame();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JButton labelButton = new JButton("Change Label");
    labelButton.addActionListener(new LabelListener());

    JButton colorButton = new JButton("Change Circle");
    colorButton.addActionListener(new ColorListener());

    label = new JLabel("I'm a label");
    MyDrawPanel drawPanel = new MyDrawPanel();

    frame.getContentPane().add(BorderLayout.SOUTH, colorButton);
    frame.getContentPane().add(BorderLayout.CENTER, drawPanel);
    frame.getContentPane().add(BorderLayout.EAST, labelButton);
    frame.getContentPane().add(BorderLayout.WEST, label);

    frame.setSize(600, 300);
    frame.setVisible(true);
  }

  // get to have TWO ActionListeners in a single class (TwoButtons)

  class LabelListener implements ActionListener {
    public void actionPerformed(ActionEvent event) {
      label.setText("Ouch!");
    }
  }

  class ColorListener implements ActionListener {
    public void actionPerformed(ActionEvent event) {
      frame.repaint();
    }
  }
}

class MyDrawPanel extends JPanel {
  public void paintComponent(Graphics g) {
    // Code to fill the oval with a random color

    // fill the entire panel with black
    g.fillRect(0, 0, this.getWidth(), this.getHeight());

    int red = (int) (Math.random() * 255);
    int green = (int) (Math.random() * 255);
    int blue = (int) (Math.random() * 255);
    Color randomColor = new Color(red, green, blue);
    g.setColor(randomColor);
    // start 70 pixels from the left, 70 from the top,
    // make it 100 pixels wide, and 100 pixels tall
    g.fillOval(70, 70, 100, 100);
  }
}
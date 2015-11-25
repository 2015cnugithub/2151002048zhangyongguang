
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class newPanel extends JPanel {
private int x;
private int y;
protected void paintComponent(Graphics g) {
super.paintComponent(g);
g.drawOval(100, 60, 100, 100);
}
}
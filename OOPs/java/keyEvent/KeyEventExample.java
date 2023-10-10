package keyEvent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class KeyEventExample implements KeyListener {

    private JLabel statusLabel;

    public KeyEventExample() {
        statusLabel = new JLabel("Press a key...");
        statusLabel.setHorizontalAlignment(JLabel.CENTER);
        statusLabel.setFont(new Font("Arial", Font.PLAIN, 24));
    }

    @Override
    public void keyTyped(KeyEvent e) {
        char keyChar = e.getKeyChar();
        statusLabel.setText("Key Typed: " + keyChar);
        System.out.println("Key Typed: " + keyChar);

    }

    @Override
    public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();
        statusLabel.setText("Key Pressed: " + KeyEvent.getKeyText(keyCode));
        System.out.println("Key Pressed: " + KeyEvent.getKeyText(keyCode));
    }

    @Override
    public void keyReleased(KeyEvent e) {
        int keyCode = e.getKeyCode();
        statusLabel.setText("Key Released: " + KeyEvent.getKeyText(keyCode));
        System.out.println("Key Released: " + KeyEvent.getKeyText(keyCode));
    }

    public static void main(String[] args) {
        KeyEventExample ke = new KeyEventExample();
        JFrame frame;
        frame = new JFrame("KeyEventExample");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.addKeyListener(ke);
        frame.add(ke.statusLabel, BorderLayout.CENTER);
        frame.setVisible(true);

    }
}

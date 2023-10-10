package appletCal;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calculator extends JApplet implements ActionListener {
    JTextField textField;
    String s0, s1, s2;
    double result;

    public void init() {
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());

        textField = new JTextField();
        textField.setEditable(false);
        panel.add(textField, BorderLayout.NORTH);

        String[] buttonLabels = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", ".", "=", "+"
        };

        JPanel buttonPanel = new JPanel(new GridLayout(4, 4));
        for (String label : buttonLabels) {
            JButton button = createButton(label);
            buttonPanel.add(button);
        }

        panel.add(buttonPanel, BorderLayout.CENTER);
        add(panel);

        s0 = s1 = s2 = "";
        result = 0.0;
    }

    public JButton createButton(String label) {
        JButton button = new JButton(label);
        button.addActionListener(this);
        return button;
    }

    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        if (command.matches("[0-9]|\\.")) {
            if (!s1.isEmpty()) {
                s2 += command;
            } else {
                s0 += command;
            }
        } else if (command.matches("[+\\-*/]")) {
            if (!s0.isEmpty() && s1.isEmpty()) {
                s1 = command;
            }
        } else if (command.equals("=")) {
            if (!s0.isEmpty() && !s1.isEmpty() && !s2.isEmpty()) {
                double num1 = Double.parseDouble(s0);
                double num2 = Double.parseDouble(s2);
                switch (s1) {
                    case "+":
                        result = num1 + num2;
                        break;
                    case "-":
                        result = num1 - num2;
                        break;
                    case "*":
                        result = num1 * num2;
                        break;
                    case "/":
                        if (num2 != 0) {
                            result = num1 / num2;
                        } else {
                            textField.setText("Error");
                            return;
                        }
                        break;
                }
                textField.setText(Double.toString(result));
                s0 = Double.toString(result);
                s1 = s2 = "";
            }
        } else if (command.equals("C")) {
            s0 = s1 = s2 = "";
            textField.setText("");
        }

        textField.setText(s0 + s1 + s2);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("calculator");

        Calculator calculatorApplet = new Calculator();
        calculatorApplet.init();
        frame.add(calculatorApplet);
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
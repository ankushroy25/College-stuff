// Ankush Roy © 08/02/2024
package tcp_calculator;

import java.io.*;
import java.net.*;

public class CalculatorServer {
    public static void main(String[] args) throws Exception {
        String operationChoice, userOptions;
        Double operand1, operand2, result = 0.0;
        ServerSocket soc = new ServerSocket(8000);
        System.out.println("Server listening on port 8000...");

        while (true) {
            Socket conSocket = soc.accept();
            BufferedReader clientInput = new BufferedReader(new InputStreamReader(conSocket.getInputStream()));
            DataOutputStream outToClient = new DataOutputStream(conSocket.getOutputStream());

            while (true) {
                userOptions = "MENU \n1-Addition \n2-Subtraction \n3-Multiplication \n4-Division \n5-Exit \nEnter operation : ";
                outToClient.writeBytes(userOptions + "\n");

                operationChoice = clientInput.readLine();
                System.out.println("Client req - Operation: " + operationChoice);

                outToClient.writeBytes("Enter operand 1 :" + "\n");
                operand1 = Double.parseDouble(clientInput.readLine());
                outToClient.writeBytes("Enter operand 2 :" + "\n");
                operand2 = Double.parseDouble(clientInput.readLine());
                System.out.println("Operands : " + operand1 + " , " + operand2);

                if (operationChoice.equals("1")) {
                    result = operand1 + operand2;
                    System.out.println(result);
                }
                switch (operationChoice) {
                    case "1":
                        result = operand1 + operand2;
                        break;
                    case "2":
                        result = operand1 - operand2;
                        break;
                    case "3":
                        result = operand1 * operand2;
                        break;
                    case "4":
                        result = operand1 / operand2;
                        break;

                    default:
                        break;
                }
                outToClient.writeBytes(Double.toString(result) + "\n");

            }
        }
    }
}

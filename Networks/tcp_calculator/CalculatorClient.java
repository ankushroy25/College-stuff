// Ankush Roy © 08/02/2024
package tcp_calculator;

import java.net.*;
import java.io.*;

public class CalculatorClient {
    public static void main(String[] args) throws Exception {
        // Connect to the server
        Socket clientSocket = new Socket("localhost", 8000);

        // Streams for sending and receiving data
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String choice, operand1, operand2, serverMessage;

        while (true) {
            String menuMessage = "";
            while (true) {
                serverMessage = inFromServer.readLine();
                if (serverMessage.equals("Enter operation : ")) {
                    menuMessage += serverMessage;
                    break;
                }
                menuMessage += serverMessage + "\n";
            }
            System.out.print(menuMessage);

            choice = br.readLine();
            if (choice.equals("5"))
                break;

            outToServer.writeBytes(choice + "\n");

            serverMessage = inFromServer.readLine();
            System.out.println(serverMessage);
            operand1 = br.readLine();
            outToServer.writeBytes(operand1 + "\n");

            serverMessage = inFromServer.readLine();
            System.out.println(serverMessage);
            operand2 = br.readLine();
            outToServer.writeBytes(operand2 + "\n");

            serverMessage = inFromServer.readLine();
            System.out.println("Answer : " + serverMessage);

        }
        clientSocket.close();

    }
}

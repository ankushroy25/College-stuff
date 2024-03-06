package parity_check;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client {
    static char calculateParityBit(String data) {
        int count = 0;
        for (char c : data.toCharArray()) {
            if (c == '1') {
                count++;
            }
        }
        return (count % 2 == 0) ? '0' : '1';
    }

    public static void main(String[] args) throws Exception {

        Socket clientSocket = new Socket("localhost", 12345);
        System.out.println("Connected to server.");

        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

        System.out.print("Enter binary input: ");
        String inputData = inFromUser.readLine();
        System.out.print("Original input: " + inputData);

        inputData += calculateParityBit(inputData);
        System.out.println("Modified input: " + inputData);

        System.out.println("Test for error injection (y or n) :");
        char ch = inFromUser.readLine().charAt(0);

        if (ch == 'y' || ch == 'Y') {
            String errorInput = inputData.substring(0, inputData.length() - 1)
                    + ((inputData.charAt(inputData.length() - 1) == '0') ? '1' : '0');
            System.out.println("Sending to server [Wrong input] : " + errorInput);
            outToServer.writeBytes(errorInput + '\n');
        } else {
            System.out.println("Sending to server [original input]: " + inputData);
            outToServer.writeBytes(inputData + '\n');
        }

        while (true) {

            String response = inFromServer.readLine();

            if (response.equals("500")) {
                System.out.println("Server requesting for retransmission...");
                System.out.println("Sending to server [original input]: " + inputData);
                outToServer.writeBytes(inputData + '\n');
            } else {
                System.out.println("Server response : " + response);
                break;
            }
        }
        clientSocket.close();
    }

}

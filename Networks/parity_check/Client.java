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
        inputData += calculateParityBit(inputData);
        outToServer.writeBytes(inputData + '\n');

        String modifiedData = inFromServer.readLine();
        if (!modifiedData.equals("ERROR")) {
            System.out.println("Data received from server after parity check: " + modifiedData);
        } else {
            System.out.println("Parity check failed. Resending data...");
            outToServer.writeBytes(inputData + '\n');
        }

        clientSocket.close();
    }

}

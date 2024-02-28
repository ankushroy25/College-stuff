package xor;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws Exception {

        Socket clientSocket = new Socket("localhost", 8000);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

        String n1, n2, result;

        System.out.println("Enter the first binary string: ");
        n1 = br.readLine();
        System.out.println("Enter the second binary string: ");
        n2 = br.readLine();

        outToServer.writeBytes(n1 + '\n');
        outToServer.writeBytes(n2 + '\n');

        result = inFromServer.readLine();
        System.out.println("Result: " + result);
        clientSocket.close();

    }
}

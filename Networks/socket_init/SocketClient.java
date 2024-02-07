package socket_init;

import java.net.*;
import java.io.*;

public class SocketClient {
    public static void main(String[] args) throws Exception {
        // Connect to the server
        Socket clientSocket = new Socket("localhost", 8000);

        // Streams for sending and receiving data
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter string : ");
            String input = br.readLine();

            outToServer.writeBytes(input + "\n");
            String modifiedInput = inFromServer.readLine();
            System.out.println("Response from server : " + modifiedInput);
        }

        clientSocket.close();
    }
}

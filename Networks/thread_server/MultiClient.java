package thread_server;

import java.net.*;
import java.io.*;

public class MultiClient {
    public static void main(String[] args) throws Exception {
        Socket clientSocket = new Socket("localhost", 8000);

        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

        int clientPort = clientSocket.getPort();
        outToServer.writeBytes(clientPort + "\n");

        String serverRes = inFromServer.readLine();
        System.out.println("Response from server : " + serverRes);

        clientSocket.close();
    }
}

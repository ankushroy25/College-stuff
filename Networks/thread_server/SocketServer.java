package thread_server;

import java.io.*;
import java.net.*;

class ServerThread extends Thread {
    Socket conSocket;

    ServerThread(Socket soc) {
        this.conSocket = soc;
    }

    public void run() {
        try {
            DataOutputStream outToClient = new DataOutputStream(conSocket.getOutputStream());
            BufferedReader clientInput = new BufferedReader(new InputStreamReader(conSocket.getInputStream()));

            int clientPort = Integer.parseInt(clientInput.readLine());
            System.out.println("Client connected from port " + clientPort);

            long currentTime = System.currentTimeMillis();
            outToClient.writeBytes("System time: " + currentTime + "\n");

            // conSocket.close();
        } catch (Exception e) {
            System.out.println("Failed to connect");
        }

    }
}

public class SocketServer {

    public static void main(String[] args) throws Exception {

        ServerSocket soc = new ServerSocket(8000);
        System.out.println("Server listening on port 8000...");

        while (true) {
            Socket conSocket = soc.accept();

            ServerThread th = new ServerThread(conSocket);
            th.start();
            System.out.println(th.getName());
        }

    }
}

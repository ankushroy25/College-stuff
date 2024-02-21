package read_write;

import java.io.*;
import java.net.*;

class ReadThread extends Thread {
    Socket conSocket;

    ReadThread(Socket soc) {
        this.conSocket = soc;
    }

    public void run() {
        try {
            BufferedReader clientInput = new BufferedReader(new InputStreamReader(conSocket.getInputStream()));

            int clientPort = Integer.parseInt(clientInput.readLine());
            System.out.println("Client connected from port " + clientPort);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}

class WriteThread extends Thread {
    Socket conSocket;

    WriteThread(Socket soc) {
        this.conSocket = soc;
    }

    public void run() {
        try {
            DataOutputStream outToClient = new DataOutputStream(conSocket.getOutputStream());

            long currentTime = System.currentTimeMillis();
            outToClient.writeBytes(Long.toString(currentTime) + "\n");
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}

public class SocketServer {

    public static void main(String[] args) throws Exception {

        ServerSocket soc = new ServerSocket(8000);
        System.out.println("Server listening on port 8000...");

        while (true) {
            Socket conSocket = soc.accept();

            ReadThread rth = new ReadThread(conSocket);
            rth.start();
            System.out.println(rth.getName());

            WriteThread wth = new WriteThread(conSocket);
            wth.start();
            System.out.println(wth.getName());

            // conSocket.close();
        }

    }
}

package tcp_chat;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

class ServerThread extends Thread {
    Socket soc;

    ServerThread(Socket soc) {
        this.soc = soc;
    }

    public void run() {
        try {
            System.out.println("Client connected from: " + soc.getInetAddress() + ", port : " + soc.getPort());
            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(soc.getInputStream()));
            DataOutputStream outToClient = new DataOutputStream(soc.getOutputStream());

            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            while (true) {
                String msg = inFromClient.readLine();
                if (msg.equals("exit")) {
                    System.out.println("Client disconnected");
                    break;
                }
                System.out.println("Received: " + msg + "\nSend: ");
                msg = br.readLine();
                outToClient.writeBytes(msg + "\n");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                soc.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}

public class Server {
    public static void main(String[] args) throws Exception {

        ServerSocket socket = new ServerSocket(8000);
        System.out.println("Server is running on port 8000...");

        while (true) {
            Socket clientSocket = new Socket();
            clientSocket = socket.accept();

            ServerThread sth = new ServerThread(clientSocket);
            sth.start();
        }
    }
}

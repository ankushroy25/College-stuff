package tcp_chat;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws Exception {

        Socket soc = new Socket("localhost", 8000);
        System.out.println("Connected to server");

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(soc.getInputStream()));
        DataOutputStream outToServer = new DataOutputStream(soc.getOutputStream());

        while (true) {
            System.out.print("Send: ");
            String msg = br.readLine();
            outToServer.writeBytes(msg + "\n");

            if (msg.equals("exit")) {
                System.out.println("Disconnected from server");
                break;
            }

            System.out.println("Received: " + inFromServer.readLine());

        }
        soc.close();
    }
}

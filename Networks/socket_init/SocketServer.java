package socket_init;

import java.io.*;
import java.net.*;

public class SocketServer {
    public static void main(String[] args) throws Exception {

        String clientStr, capitalStr;
        ServerSocket soc = new ServerSocket(8000);
        System.out.println("Server listening on port 8000...");

        while (true) {
            Socket conSocket = soc.accept();
            BufferedReader clientInput = new BufferedReader(new InputStreamReader(conSocket.getInputStream()));
            DataOutputStream outToClient = new DataOutputStream(conSocket.getOutputStream());

            while ((clientStr = clientInput.readLine()) != null) {
                System.out.println("Received from Client: " + clientStr);

                capitalStr = clientStr.toUpperCase();
                outToClient.writeBytes(capitalStr + "\n");
            }
        }

    }
}

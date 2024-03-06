package parity_check;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    private static int calculateParity(String data) {
        int count = 0;
        for (char c : data.toCharArray()) {
            if (c == '1')
                count++;
        }
        return count % 2;
    }

    public static void main(String[] args) throws Exception {

        ServerSocket soc = new ServerSocket(12345);
        System.out.println("Server listening on port 12345...");

        while (true) {
            Socket clienSocket = soc.accept();
            System.out.println("Client connected.");

            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(clienSocket.getInputStream()));
            DataOutputStream outToClient = new DataOutputStream(clienSocket.getOutputStream());

            while (true) {

                String inputData = inFromClient.readLine();
                System.out.println("Data received from client: " + inputData);

                int parity = calculateParity(inputData);
                if (parity == 0) {
                    String result = inputData.substring(0, inputData.length() - 1);
                    System.out.println("Check successful. Data without parity: " + result);
                    outToClient.writeBytes(result + '\n');
                    break;
                } else {
                    System.out.println("Parity check failed. Requesting retransmission...");
                    outToClient.writeBytes("500\n");
                }

            }
            clienSocket.close();
        }
    }

}

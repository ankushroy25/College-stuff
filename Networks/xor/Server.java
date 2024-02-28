package xor;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    static String performXOR(String s1, String s2) {
        String result = "";
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) == s2.charAt(i))
                result += "0";
            else
                result += "1";
        }
        return result;
    }

    public static void main(String[] args) throws Exception {

        ServerSocket soc = new ServerSocket(8000);
        Socket clientSocket = soc.accept();

        BufferedReader inFromClient = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        DataOutputStream outToClient = new DataOutputStream(clientSocket.getOutputStream());

        String n1, n2, result;
        n1 = inFromClient.readLine();
        n2 = inFromClient.readLine();

        result = performXOR(n1, n2);
        outToClient.writeBytes(result + "\n");
        soc.close();
    }
}

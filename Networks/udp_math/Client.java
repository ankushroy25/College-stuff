package udp_math;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        DatagramSocket dsoc = new DatagramSocket();
        System.out.println("Client started...");

        while (true) {

            String msg = "";

            System.out.print("1-Add 2-Subtract 3-Multiply 4-Divide \nChoose operation : ");
            msg += sc.next() + " ";
            System.out.print("Enter the first number: ");
            msg += sc.next() + " ";
            System.out.print("Enter the second number: ");
            msg += sc.next();

            InetAddress address = InetAddress.getByName("localhost");

            DatagramPacket packet = new DatagramPacket(msg.getBytes(), msg.getBytes().length, address, 8000);
            dsoc.send(packet);

            byte[] buffer = new byte[1024];
            DatagramPacket packetRec = new DatagramPacket(buffer, buffer.length);
            dsoc.receive(packetRec);
            String res = new String(packetRec.getData());
            System.out.println("From Server: " + res.trim());

            System.out.println("Do you want to continue? (y/n)");
            String choice = sc.next();
            if (choice.equals("n")) {
                break;
            }
        }
        sc.close();
        dsoc.close();
    }
}

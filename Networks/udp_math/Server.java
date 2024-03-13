package udp_math;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class Server {
    public static void main(String[] args) throws Exception {

        DatagramSocket socket = new DatagramSocket(8000);
        byte buffer[] = new byte[1024];

        while (true) {
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            socket.receive(packet);

            String msg = new String(packet.getData());
            System.out.println("Message from client: " + msg.trim());

            String numbers[] = msg.trim().split(" ");
            String choice = numbers[0];
            int num1 = Integer.parseInt(numbers[1]);
            int num2 = Integer.parseInt(numbers[2]);
            int sum = 0;
            switch (choice) {
                case "1":
                    sum = num1 + num2;
                    break;
                case "2":
                    sum = num1 - num2;
                    break;
                case "3":
                    sum = num1 * num2;
                    break;
                case "4":
                    sum = num1 / num2;
                    break;

                default:
                    break;
            }
            msg = "Answer " + Integer.toString(sum);
            DatagramPacket packetSend = new DatagramPacket(msg.getBytes(), msg.getBytes().length, packet.getAddress(),
                    packet.getPort());
            socket.send(packetSend);

        }
    }
}

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Server {
    public static void main(String[] args) {
        try {
            DatagramSocket dsocket = new DatagramSocket(50000);
            byte[] buffer = new byte[2048];
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

            while (true) {
                dsocket.receive(packet);
                byte[] bi = packet.getData();
                String msg = new String(bi);
                System.out.println(msg.trim() + " From port: " + packet.getPort());

                InetAddress address = packet.getAddress();
                String msg1 = "Acknowledged";
                DatagramPacket packet1 = new DatagramPacket(msg1.getBytes(), msg1.getBytes().length, address,
                        packet.getPort());
                dsocket.send(packet1);
            }
        } catch (Exception e) {
        }
    }
}

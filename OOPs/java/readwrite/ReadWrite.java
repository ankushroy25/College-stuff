package readwrite;

import java.io.*;
import java.util.Scanner;

public class ReadWrite {
    public static void main(String[] args) throws IOException {

        System.out.println("\n----Writing using Buffered Writer----");
        BufferedWriter br = new BufferedWriter(new FileWriter("test.txt", true));
        BufferedReader brin = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter text : ");
        br.write("\n" + brin.readLine());
        br.close();

        System.out.println("\n----Reading using BufferedReader-----");
        BufferedReader bre = new BufferedReader(new FileReader("test.txt"));
        String line;
        while ((line = bre.readLine()) != null) {
            System.out.println(line);
        }
        bre.close();

        System.out.println("\n----Reading using scanner----");
        Scanner sc = new Scanner(new File("test.txt"));

        while (sc.hasNextLine()) {
            System.out.println(sc.nextLine());
        }
    }
}

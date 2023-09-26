package adminHod;

import AdminFacHod;

public class Main {
    public static void main(String[] args) {
        // Create an object of HOD class
        HOD hod = new HOD("John Doe", 101);

        // Call methods from Admin interface
        hod.selectCr(3, 'A');

        // Call methods from Faculty class
        hod.display();
        hod.teach(5);
    }
}

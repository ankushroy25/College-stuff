import Organisation.Employee;
import Project.Manager;

import java.text.ParseException;

public class Main {
    public static void main(String[] args) throws ParseException {
        // Create two managers
        Manager manager1 = new Manager(101, "John Doe", "15-05-1985", "IT", "Project A", 5);
        Manager manager2 = new Manager(102, "Alice Smith", "20-08-1978", "HR", "Project B", 3);

        // Display manager details
        System.out.println("Manager 1 Details:");
        manager1.display();

        System.out.println("\nManager 2 Details:");
        manager2.display();
    }
}

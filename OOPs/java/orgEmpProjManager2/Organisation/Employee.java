package Organisation;

public class Employee {
    private int employeeId;
    private String name, dob;
    private String department;

    public Employee(int employeeId, String name, String dob, String department) {
        this.employeeId = employeeId;
        this.name = name;
        this.dob = dob;
        this.department = department;
    }

    public void display() {
        System.out.println("Employee ID: " + employeeId);
        System.out.println("Name: " + name);
        System.out.println("Date of Birth: " + dob);
        System.out.println("Department: " + department);
    }
}

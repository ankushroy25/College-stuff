class Employee {
    private String name, department;
    private int employeeId, joiningDate;
    private double feedbackScore, salary;

    private static String organizationName;

    public Employee(String name, int employeeId, int joiningDate, String department, double salary,
            double feedbackScore, String organizationName) {
        this.name = name;
        this.employeeId = employeeId;
        this.joiningDate = joiningDate;
        this.department = department;
        this.feedbackScore = feedbackScore;
        this.salary = salary;
        Employee.organizationName = organizationName;
    }

    // Display method
    public void display() {
        System.out.println("Organization Name: " + organizationName);
        System.out.println("Employee Name: " + name);
        System.out.println("Employee ID: " + employeeId);
        System.out.println("Joining Date: " + joiningDate);
        System.out.println("Department: " + department);
        System.out.println("Feedback Score: " + feedbackScore);
    }

    static class Increment {
        public static double calIncrement(Employee emp) {
            double increment = emp.joiningDate * 10 + emp.feedbackScore * 100;

            return increment;
        }
    }

    class Promotion {
        // Method to check if an employee should be promoted
        public boolean promote() {
            double increment = Increment.calIncrement(Employee.this);

            return (increment > (0.5 * salary));
        }
    }
}

public class EmployeeMain {
    public static void main(String[] args) {
        Employee emp = new Employee("John Doe", 12345, 2000, "IT", 500000, 51, "HITK");

        emp.display();

        // Calculate and display the increment
        double incrementAmount = Employee.Increment.calIncrement(emp);
        System.out.println("Increment Amount: " + incrementAmount);

        // Check if the employee should be promoted
        Employee.Promotion promotionCheck = emp.new Promotion();
        boolean shouldPromote = promotionCheck.promote();
        System.out.println("Should Promote: " + shouldPromote);
    }
}

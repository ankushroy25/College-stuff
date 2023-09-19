package Project;

import Organisation.Employee;

public class Manager extends Employee {
    private String projectName;
    private int numberOfTeams;

    public Manager(int employeeId, String name, String dob, String department, String projectName, int numberOfTeams) {
        super(employeeId, name, dob, department);
        this.projectName = projectName;
        this.numberOfTeams = numberOfTeams;
    }

    public void display() {
        super.display();
        System.out.println("Project Name: " + projectName);
        System.out.println("Number of Teams: " + numberOfTeams);
    }
}

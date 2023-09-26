// package adminHod;

// interface Admin {
//     String colgName = "ABC College"; // Constant colgName

//     void selectCr(int year, char section); // Abstract method selectCr
// }

// Define the abstract Faculty class
abstract class Faculty {
    String name;
    int facultyId;

    // Constructor for Faculty class
    public Faculty(String name, int facultyId) {
        this.name = name;
        this.facultyId = facultyId;
    }

    // Abstract method teach
    abstract void teach(int semester);

    // Method to display faculty information
    void display() {
        System.out.println("Name: " + name);
        System.out.println("Faculty ID: " + facultyId);
    }
}

// Define the HOD class that implements Admin and extends Faculty
class HOD extends Faculty implements Admin {
    // Constructor for HOD class
    public HOD(String name, int facultyId) {
        super(name, facultyId);
    }

    // Implementation of selectCr method from Admin interface
    @Override
    public void selectCr(int year, char section) {
        System.out.println("Selected CR for Year " + year + " Section " + section);
    }

    // Implementation of teach method from Faculty class
    @Override
    void teach(int semester) {
        System.out.println("Teaching Semester " + semester);
    }
}

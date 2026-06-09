

import java.util.Scanner;

public class Student 


{

    // Object Variables
    String id;
    String name;
    String department;
    double cgpa;





    // Class Variables
    static String university = "University of Liberal Arts Bangladesh (ULAB)";
    static int totalStudents = 0;




    // Parameterized Constructor
    Student(String id, String name, String department, double cgpa) 
    
    
    {

        this.id = id;
        this.name = name;
        this.department = department;
        this.cgpa = cgpa;

        totalStudents++;
    }





    // Object Method
    void displayStudentDetails() 
    
    
    
    {

        System.out.println("\nStudent Details");
        System.out.println("-------------------------");
        System.out.println("ID : " + id);
        System.out.println("Name : " + name);
        System.out.println("Department : " + department);
        System.out.println("CGPA : " + cgpa);
        System.out.println("University : " + university);
    }






    // Class Method
    static void displayTotalStudents() 
    
    
    
    {

        System.out.println("\nTotal Number of Students : " + totalStudents);
    }





    public static void main(String[] args) 
    
    {



        Scanner s1 = new Scanner(System.in);




        // Student 1 Input
        System.out.println("Enter the 1st Student Information");




        System.out.print("ID : ");
        String id1 = s1.nextLine();




        System.out.print("Name : ");
        String name1 = s1.nextLine();




        System.out.print("Department : ");
        String department1 = s1.nextLine();





        System.out.print("CGPA : ");
        double cgpa1 = s1.nextDouble();
        s1.nextLine();





        Student student1 = new Student(id1, name1, department1, cgpa1);





        // Student 2 Input
        System.out.println("\nEnter the 2nd Student Information");





        System.out.print("ID : ");
        String id2 = s1.nextLine();




        System.out.print("Name : ");
        String name2 = s1.nextLine();





        System.out.print("Department : ");
        String department2 = s1.nextLine();





        System.out.print("CGPA : ");
        double cgpa2 = s1.nextDouble();
        s1.nextLine();





        Student student2 = new Student(id2, name2, department2, cgpa2);





        // Student 3 Input
        System.out.println("\nEnter the 3rd Student Information");





        System.out.print("ID : ");
        String id3 = s1.nextLine();





        System.out.print("Name : ");
        String name3 = s1.nextLine();





        System.out.print("Department : ");
        String department3 = s1.nextLine();





        System.out.print("CGPA : ");
        double cgpa3 = s1.nextDouble();





        Student student3 = new Student(id3, name3, department3, cgpa3);





        // Display Student Details
        System.out.println("\n===== Student 1 Information =====");
        student1.displayStudentDetails();






        System.out.println("\n===== Student 2 Information =====");
        student2.displayStudentDetails();





        System.out.println("\n===== Student 3 Information =====");
        student3.displayStudentDetails();




        // Display Total Students
        Student.displayTotalStudents();




        
        s1.close();
    }
}
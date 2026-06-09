

import java.util.Scanner;


public class Employee 

{



    // Object Variables
    String name;
    int age;
    String designation;
    double salary;




    // Class Variables
    static String companyName = "ABC Corporation";
    static String companyAddress = "Dhaka, Bangladesh";
    static int totalEmployees = 0;




    // Parameterized Constructor
    Employee(String name, int age, String designation, double salary) {
        this.name = name;
        this.age = age;
        this.designation = designation;
        this.salary = salary;

        totalEmployees++;



    }




    // Object Method
    void displayEmployeeDetails() 
    
    {
        System.out.println("\nEmployee Details");
        System.out.println("--------------------");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Designation: " + designation);
        System.out.println("Salary: " + salary);
        System.out.println("Company Name: " + companyName);
        System.out.println("Company Address: " + companyAddress);


    }





    // Class Method
    static void displayTotalEmployees() 
    
    {
        System.out.println("\nTotal Number of Employees: " + totalEmployees);
    }





    public static void main(String[] args) 
    
    {

        Scanner s1 = new Scanner(System.in);



        // Employee 1
        System.out.println("Enter Employee 1 Information");




        System.out.print("Name: ");
        String name1 = s1.nextLine();



        System.out.print("Age: ");
        int age1 = s1.nextInt();
        s1.nextLine();



        System.out.print("Designation: ");
        String designation1 = s1.nextLine();



        System.out.print("Salary: ");
        double salary1 = s1.nextDouble();
        s1.nextLine();



        Employee employee1 = new Employee(name1, age1, designation1, salary1);




        // Employee 2
        System.out.println("\nEnter Employee 2 Information");



        System.out.print("Name: ");
        String name2 = s1.nextLine();




        System.out.print("Age: ");
        int age2 = s1.nextInt();
        s1.nextLine();



        System.out.print("Designation: ");
        String designation2 = s1.nextLine();




        System.out.print("Salary: ");
        double salary2 = s1.nextDouble();
        s1.nextLine();




        Employee employee2 = new Employee(name2, age2, designation2, salary2);



        // Employee 3
        System.out.println("\nEnter Employee 3 Information");



        System.out.print("Name: ");
        String name3 = s1.nextLine();



        System.out.print("Age: ");
        int age3 = s1.nextInt();
        s1.nextLine();



        System.out.print("Designation: ");
        String designation3 = s1.nextLine();




        System.out.print("Salary: ");
        double salary3 = s1.nextDouble();




        Employee employee3 = new Employee(name3, age3, designation3, salary3);




        // Display Employee Details
        employee1.displayEmployeeDetails();
        employee2.displayEmployeeDetails();
        employee3.displayEmployeeDetails();




        // Display Total Employees
        Employee.displayTotalEmployees();

        s1.close();


        
    }
}
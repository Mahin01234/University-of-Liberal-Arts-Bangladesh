

package com.mycompany.student;

/**
 *
 * @author DELL
 */


public class Student 
{

    private String name;
    private String id;
    private double cgpa;
    private String department;

    // Constructor 1
    public Student(String name, String id, double cgpa, String department) 
    {
        this.name = name;
        this.id = id;
        this.cgpa = cgpa;
        this.department = department;
    }

    // Constructor 2
    public Student(String name, String id) 
    {
        this.name = name;
        this.id = id;
        this.cgpa = 0.0;
        this.department = "Not Specified";
    }

    // Overloaded Method 1
    public void show() 
    {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("CGPA: " + cgpa);
        System.out.println("Department: " + department);
    }

    // Overloaded Method 2
    public void show(String title) 
    {
        System.out.println(title);
        show();
    }
}
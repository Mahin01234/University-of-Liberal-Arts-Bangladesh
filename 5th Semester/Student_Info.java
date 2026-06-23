/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.student;
import java.util.Scanner;
/**
 *
 * @author DELL
 */


public class Student_Info {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        sc.nextLine();

        Student[] students = new Student[n];

        for (int i = 0; i < n; i++) {

            System.out.println("\nEnter details for Student " + (i + 1));

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("ID: ");
            String id = sc.nextLine();

            System.out.print("CGPA: ");
            double cgpa = sc.nextDouble();
            sc.nextLine();

            System.out.print("Department: ");
            String department = sc.nextLine();

            students[i] = new Student(name, id, cgpa, department);
        }

        System.out.println("\n===== Student Information =====");

        for (int i = 0; i < n; i++) {
            students[i].show("Student " + (i + 1) + ":");
            System.out.println();
        }

        // Demonstrating Constructor Overloading
        System.out.println("===== Constructor Overloading Demo =====");

        Student demo = new Student("Mahin", "242014165");

        demo.show("Demo Student:");

        sc.close();
    }
}
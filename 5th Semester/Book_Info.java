
package com.mycompany.student;



import java.util.Scanner;



/**
 *
 * @author DELL
 */


public class Book_Info {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of books: ");
        int n = sc.nextInt();
        sc.nextLine();

        Book[] books = new Book[n];

        // Input books
        for (int i = 0; i < n; i++) {

            System.out.println("\nEnter details for Book " + (i + 1));

            System.out.print("Title: ");
            String title = sc.nextLine();

            System.out.print("Author: ");
            String author = sc.nextLine();

            System.out.print("Price: ");
            double price = sc.nextDouble();

            System.out.print("Year Published: ");
            int year = sc.nextInt();
            sc.nextLine();

            books[i] = new Book(title, author, price, year);
        }

        // Display all books (full format)
        System.out.println("\n===== BOOK DETAILS (FULL FORMAT) =====");

        for (int i = 0; i < n; i++) {
            books[i].display("Book " + (i + 1) + ":");
            System.out.println();
        }

        // Demonstrating constructor overloading
        System.out.println("===== CONSTRUCTOR OVERLOADING DEMO =====");

        Book demo = new Book("Clean Code", "Robert C. Martin");
        demo.display(true);

        sc.close();
    }
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.student;

/**
 *
 * @author DELL
 */


public class Book {

    private String title;
    private String author;
    private double price;
    private int yearPublished;

    // Constructor 1 (All fields)
    public Book(String title, String author, double price, int yearPublished) {
        this.title = title;
        this.author = author;
        this.price = price;
        this.yearPublished = yearPublished;
    }

    // Constructor 2 (Partial fields)
    public Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.price = 0.0;
        this.yearPublished = 0;
    }

    // Method Overloading - display 1
    public void display() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: " + price);
        System.out.println("Year Published: " + yearPublished);
    }

    // Method Overloading - display 2
    public void display(String header) {
        System.out.println(header);
        display();
    }

    // Method Overloading - display 3 (short format)
    public void display(boolean shortFormat) {
        if (shortFormat) {
            System.out.println(title + " by " + author + " (" + yearPublished + ")");
        } else {
            display();
        }
    }
}

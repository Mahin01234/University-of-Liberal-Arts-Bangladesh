/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.movie;




public class MovieDetails 

{ 
    
    public static void main (String[] args) 
    {
        
        Movie s1 = new Movie (25, 30000, "Rahim", "Developer") ; 
        
        Movie s2 = new Movie (21, 20000, "Mahim", "Developer") ; 
        
        Movie s3 = new Movie (28, 40000, "Mahi", "Developer") ; 
        
        s1.display();
        System.out.println ("Company Name : " + Movie.company_name) ; 
        System.out.println ("Company Addess : " + Movie.company_address ) ; 
        
        
        s2.display();
        System.out.println ("Company Name : " + Movie.company_name) ; 
        System.out.println ("Company Addess : " + Movie.company_address ) ; 
        
        
        s3.display();
        System.out.println ("Company Name : " + Movie.company_name) ; 
        System.out.println ("Company Addess : " + Movie.company_address ) ;  
        
        
        
        s1.display();
        s2.display();
        s3.display(); 
        
        
        Movie.Total_employees() ; 
    }
    
}

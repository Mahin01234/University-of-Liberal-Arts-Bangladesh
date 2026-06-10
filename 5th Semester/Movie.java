/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.movie;

public class Movie 
{
    String Name, Designation ; 
    int age , salary ;  
    
    
    
    static String company_name = "XYZ" ; 
    static String company_address =  "DHAKA" ; 
    
    
    static int totalnumberofemployee  ; 
    
    
    public Movie (int age , int salary, String Name, String Designation ) 
    {

          this.age = age ; 
          this.salary = salary ; 
          this.Name = Name ; 
          this.Designation = Designation ; 
          
          
          totalnumberofemployee++ ; 
          
          
          
    
    }

     
    void display()
    {
        System.out.println ("Name : " + Name) ; 
        System.out.println ("Salary : " + salary) ; 
        System.out.println ("Age : " + age) ; 
        System.out.println ("Designation : " + Designation ) ;
        
        System.out.println ("Company_name : " +  company_name ) ; 
        
        System.out.println ("Company_address : " +  company_address ) ; 
        
        
        
        
        
        
    }
    
    
    
    static void Total_employees() 
    {
        System.out.println("Total Employees: " + totalnumberofemployee);
    }
  
    
  
        
}






 




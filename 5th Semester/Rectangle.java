
package com.mycompany.lab_report_1;



import java.util.Scanner ; 


public class Rectangle

{
    
    double length ; 
    double width  ; 
    
    
    
    Rectangle ( double length , double width ) 
    {
        this.length = length ; 
        this.width = width ; 
    }
    
    
    double Area() 
    {
        return length * width ; 
    }
    
    
    double Perimeter() 
    {
        return 2 * ( length + width ) ; 
    }
    
    
    
    void display()
    {
        System.out.println("The Length is : " + length ) ;
        
        System.out.println("The Width is : " + width ) ; 
        
        System.out.println("The Area is : " + Area()  ) ;
        
        System.out.println("The Perimeter is : " + Perimeter()  ) ; 
        
    }
    
    
    
    public static void main (String[] args ) 
    {
        
        Scanner s1 = new Scanner (System.in  ) ; 
        
        
        System.out.println ("Enter the length : " ) ; 
        double length = s1.nextDouble() ; 
        
        
        
        
        System.out.println ("Enter the width : ") ; 
        double width = s1.nextDouble() ;
        
        
        
        Rectangle rectangle = new Rectangle (length , width ) ; 
        
        
        
        System.out.println ("The Rectangle info : ") ; 
        
        rectangle.display() ; 
        
        
        s1.close () ; 
       
        
    }
    
    
    
}   
    


//package com.mycompany.basic;

//public class Student {
//    
//}
//



package com.mycompany.Basic ;

public class Student {
   int id;  //instance variable/object variable
   String name, email; 
   double cgpa;
   String hometown;
   
   void display(){  //instance method
    System.out.println("ID: "+id);
    System.out.println("Name: "+name);
    System.out.println("Email: " +email);
    System.out.println("CGPA: "+cgpa);
    System.out.println("Hometown: "+hometown);
   }
   
  public static void main(String args[]){
    Student s1=new Student(); //object creation
    s1.id=123;
    s1.name="XYZ";
    s1.email="xyz@gmail.com";
    s1.hometown="Dhaka";
    s1.cgpa=3.5;
    s1.display();
    
    
    
    
    Student s2=new Student(); //object creation
    s2.id=567;
    s2.name="ABC";
    s2.email="asd@gmail.com";
    s2.hometown="Dhaka";
    s2.cgpa=2.09 ;
    s2.display();
  } 
   
}

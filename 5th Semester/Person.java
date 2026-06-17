
package com.mycompany.lab_4;

/**
 *
 * @author Student
 */
public class Person 

{
    
    String name , gender , address ; 
    int age ; 

    

    
    
    // constructor overload 
    
    public Person(String name, String gender, String address, int age) 
    {
        this.name = name;
        this.gender = gender;
        this.address = address;
        this.age = age;
    }
    
    
    
    
    
    
    
    
    public Person(String name, String gender, int age) 
    {
        this.name = name;
        this.gender = gender;
        this.age = age;
    }
    
    
    
    
    
    
    // Method overloding
    void display () 
    {
        
        System.out.println ("Name : " + name + "Gender : " + gender + "Age : " + age + "Addresss : " + address ) ;
    }
    
    
    
    void display (int i) 
    {
        
        System.out.println ("Name : " + name + "Gender : " + gender + "Age : " + age ) ;
    }
    
    
    
    
    
    
}

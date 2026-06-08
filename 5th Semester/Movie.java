
package com.mycompany.lab_report_1;


import java.util.Scanner ; 


public class Movie 
{
    
    
    String title , genre , lead_actor , director , review ; 
    
    int release_year ; 
    
    double rating ; 
    
    
    
    
    Movie ( String title , String genre , String Lead_Actor , String director , int release_year , double rating ) 
    {
        
        this.title = title ; 
        this.genre = genre ; 
        this.lead_actor = Lead_Actor ; 
        this.rating = rating ; 
        this.release_year = release_year ; 
        this.director = director ; 
        
        
        
        
        if ( rating <= 5 ) 
        {
            review = "NOT GOOD" ; 
        }
        else 
        {
            review = "GOOD" ; 
        }
    } 
    
    
    
    
    
    void display() 
    {
        System.out.println("Enter the Title is : " + title ) ; 
        
        
        System.out.println("Enter the Genre is : " + genre ) ;
        
        System.out.println("Enter the Lead_Actor is : " + lead_actor ) ;
        
        System.out.println("Enter the Director is : " + director ) ;
        
        System.out.println("Enter the Release_Year is : " + release_year ) ;
        
        
        System.out.println("Enter the rating is : " + rating ) ;
        
        
        System.out.println("Enter the Review is : " + review  ) ;
        
    }
    
    
    
    public static void main (String[] args ) 
    {
        
        Scanner s1 = new Scanner (System.in ) ; 
        
        
        System.out.println("Enter the 1st Movis Info."  ) ;
        
        
        System.out.println ("Title is : ") ;
        String title = s1.nextLine() ; 
        
        
        System.out.println ("Genre is : ") ;
        String genre = s1.nextLine() ;  
        
        
        
        System.out.println ("Lead Actor is : ") ;
        String lead_actor = s1.nextLine() ;
        
        
        System.out.println ("Director is : ") ;
        String Director = s1.nextLine() ;  
        
        
        
        System.out.println ("Release_Year is : ") ;
        int release_year = s1.nextInt() ;  
        
        
        
        System.out.println ("Rating is : ") ;
        double rating = s1.nextDouble() ; 
        
        
        
        Movie movie = new Movie ( title , genre , lead_actor , Director , release_year , rating) ; 
        
        
        
        s1.nextLine(); 
             
        

         
        
        
        System.out.println("Enter the 2nd Movis Info."  ) ;
        
        
        System.out.println ("Title is : ") ;
        String title2 = s1.nextLine() ; 
        
        
        System.out.println ("Genre is : ") ;
        String genre2 = s1.nextLine() ;  
        
        
        
        System.out.println ("Lead Actor is : ") ;
        String lead_actor2 = s1.nextLine() ;
        
        
        System.out.println ("Director is : ") ;
        String Director2 = s1.nextLine() ;  
        
        
        
        System.out.println ("Release_Year is : ") ;
        int release_year2 = s1.nextInt() ;  
        
        
        
        System.out.println ("Rating is : ") ;
        double rating2 = s1.nextDouble() ; 
        

        
        
        Movie movie2 = new Movie ( title2 , genre2 , lead_actor2 , Director2 , release_year2 , rating2) ; 
         
        
        
        System.out.println ("\nThe 1st Movie Information is : ") ; 

        movie.display() ; 
        
        
        System.out.println ("\nThe 2nd Movie Information is : ") ; 
        movie2.display() ;
        
        
        s1.close() ; 
        
        
    }
}

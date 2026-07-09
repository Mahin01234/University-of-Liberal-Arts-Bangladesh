
package com.mycompany.inheritance;




class Vehicle
{
    private String brand ;
    private int model ;
    private int price ;
    private String color ;

   
    public Vehicle(String brand, int model, int price, String color) 
    {
        this.brand = brand ;
        this.model = model ;
        this.price = price ;
        this.color = color ;
    } 

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public int getModel() {
        return model;
    }

    public void setModel(int model) {
        this.model = model;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }


    
    
    
    
    
   class Car extends Vehicle 
   {
      private int doors;

    
    
      public Car(String brand, int model, int price, String color, int doors) 
    
        {
             super(brand, model, price, color);
             this.doors = doors;
        }

    
    
    
        @Override
        public String toString() 
        {
               return "Car [Brand=" + getBrand() + "\nModel=" + getModel() + "\nPrice=" + getPrice() + "\nColor=" + getColor() +  "\nDoors=" + doors + "]";
        }
    }

   
   
   
   
   
   
    class Motorcycle extends Vehicle 
    {
        
        private int engineCC;

       public Motorcycle(String brand, int model, int price, String color, int engineCC) 
    
        {
            super(brand, model, price, color);
            this.engineCC = engineCC;
        }

    
    
    
       @Override
       public String toString() 
       {
              return "Motorcycle [Brand=" + getBrand() + "\nModel=" + getModel() + "\nPrice=" + getPrice() + "\nColor=" + getColor() + "\nEngine CC=" + engineCC + "]";
       }
   }
    
    
    
    
    
    
    public class Inheritance 
    {
        
        public static void main(String[] args)
        {
            
        }
    }
    
}
    


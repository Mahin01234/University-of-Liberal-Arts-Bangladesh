#include<stdio.h>
#include<stdint.h>
int main()
{
    int a[5] = {1,2,3,4,5} ; 
    printf("The Address is (hexadecimal) : ") ; 
    //hexadecimal 
    printf ("%p %p" , (void*)&a[2] , (void*)&a[3]) ; 
    // decimal 
    printf("\nThe Address is (decimal) : ") ; 
    printf("%lu %lu" , (unsigned long) (uintptr_t) &a[1] , (unsigned long) (uintptr_t) &a[2] ) ; 
    
    return 0 ; 
}




/* 

Note : 
1. "C" -> Hexadecimal সময় %p use করতে হবে । কারণ %p proper hexadecimal pointer address আসে ।  
2. %p use করার সময় আবশ্যই (void*)  দিতে হবে । 
3. আমি যদি decimal use করি তাহলে %lu %lu (unsigned long) (uintptr_t) use করতে হবে । 
এই টা use না করলে undefined behavior or system garbage value or crash হতে পারে . 

"C++" -> & (and person) use করলে হবে । 

*/
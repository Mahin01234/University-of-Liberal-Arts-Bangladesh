#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value ; 
    struct Node * next ; 
} ; 

void insert_tail (struct Node ** head , int value) 
{
    struct Node * newnode = (struct Node * ) malloc (sizeof (struct Node ) ) ; 
    newnode->value = value ; 
    newnode->next = NULL ; 

    if (*head == NULL) 
    {
        * head = newnode ; 
        return ; 
    }

    struct Node * temp =* head ; 
    while (temp->next != NULL) 
    { 
        temp = temp->next ;   
    }
    temp->next = newnode ; 
}    

void insert_tail_print (struct Node * head ) 
{
    struct Node * temp = head ; 
    while (temp != NULL)
    {
        printf("%d " , temp->value) ; 
        temp = temp->next ; 
    }
    printf("\n") ; 
} 



int main() 
{
    struct Node * head = NULL ; 

    int n , m , value ; 

    printf("The element is : ") ; 
    scanf("%d" , &n) ; 
    
    for(int i=0 ; i<n ; i++) 
    {
        printf("The Node is %d : " , i + 1) ; 
        scanf("%d" , &value) ; 
        insert_tail(&head , value) ; 
    }
    printf("The tail is : ") ; 
    insert_tail_print (head) ;   


    printf("The new element is : ") ; 
    scanf("%d" , &m) ; 
    for(int i=0 ; i<m ; i++) 
    {
        printf("The Node is %d : " , i + 1) ; 
        scanf("%d" , &value) ; 
        insert_tail (&head , value) ;
    }
    printf("After the new tail element is : ") ; 
    insert_tail_print (head) ;  

    printf("\n" ) ; 

    return 0 ; 

} 








// Output : 
// The element is : 2
// The Node is 1 : 1
// The Node is 2 : 2
// The tail is : 1 2 
// The new element is : 3
// The Node is 1 : 3
// The Node is 2 : 4
// The Node is 3 : 5
// After the new tail element is : 1 2 3 4 5

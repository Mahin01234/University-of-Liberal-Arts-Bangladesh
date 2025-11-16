#include<stdio.h>
#include<stdlib.h>





struct Node 
{
    int value ; 
    struct Node * next ; 
} ;





// ======== Tail function =============
void insert_tail (struct Node ** head , int value ) 
{
    struct Node * newnode = (struct Node *) malloc (sizeof (struct Node) ) ; 
    newnode->value = value ; 
    newnode->next = NULL ; 

    if (*head == NULL) 
    {
        *head = newnode ; 
        return ; 
    }

    struct Node * temp = * head ; 

    while (temp->next != NULL) 
    {
        temp = temp->next ; 
    }
    temp->next = newnode ; 
}






// ============== head function ================
void insert_head (struct Node ** head , int value) 
{
    struct Node * newnode = (struct Node * ) malloc (sizeof (struct Node )  )  ; 
    newnode->value = value ; 
    newnode->next = *head ; 
    *head = newnode ;  
}






// ============== print function =================
void insert_head_print (struct Node * head) 
{
    struct Node * temp = head ;
    while (temp != NULL) 
    {
        printf("%d " , temp->value) ; 
        temp = temp->next ; 
    }
    printf("\n") ; 
}







// ============ main function ================
int main()
{
    struct Node * head = NULL;
    int n , m , value ; 
    printf("enter the element : ") ; 
    scanf("%d" , &n) ; 

    for (int i=0 ; i<n ; i++) 
    {
        printf("the node is : %d " , i + 1) ; 
        scanf("%d" , &value) ; 
        insert_tail(&head , value) ; 
    }

    // printf("enter the elements : ") ; 
    // insert_head_print (head) ;  


    printf("The head is : ") ; 
    struct Node * temp = head ; 
    while (temp != NULL) 
    {
        printf("%d " , temp->value) ; 
        temp = temp->next ; 
    }
    printf("\n") ; 




    printf("new element is : ") ; 
    scanf("%d" , &m) ; 
    for(int i=0 ; i<m ; i++)
    {
        printf("the node is : %d " , i+1) ; 
        scanf("%d" , &value) ;  
        insert_head(&head , value) ; 
    }

    // printf("enter the insert head element : ") ; 
    // insert_head_print (head) ; 


    printf("The new elements is : ") ; 
    temp = head ; 
    while (temp != NULL) 
    {
        printf("%d " , temp->value) ; 
        temp = temp->next ; 
    }
    printf("\n") ;



    return 0 ; 
}




//Output : 
// enter the element : 4 
// the node is : 1 10
// the node is : 2 20
// the node is : 3 30
// the node is : 4 40
// The head is : 10 20 30 40 
// new element is : 3
// the node is : 1 120
// the node is : 2 130
// the node is : 3 140
// The new elements is : 140 130 120 10 20 30 40
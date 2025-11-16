#include <stdio.h>
#include <stdlib.h>



// Node structure
struct Node
{
    int value;
    struct Node* next;
};




int main()
{
    // 3টা নোড ডাইনামিকালি তৈরি করব
    struct Node* a = (struct Node*)malloc(sizeof(struct Node));
    struct Node* b = (struct Node*)malloc(sizeof(struct Node));
    struct Node* c = (struct Node*)malloc(sizeof(struct Node));


    
    // data assign
    a->value = 10;
    b->value = 20;
    c->value = 300;


    
    // connection
    a->next = b;
    b->next = c;
    c->next = NULL;

    // print values
    printf("%d ", a->value);
    printf("%d ", a->next->value);
    printf("%d\n", a->next->next->value);


    
    // memory free করা ভালো অভ্যাস
    free(a);
    free(b);
    free(c);


    
    return 0;
}




Output:
10 20 300

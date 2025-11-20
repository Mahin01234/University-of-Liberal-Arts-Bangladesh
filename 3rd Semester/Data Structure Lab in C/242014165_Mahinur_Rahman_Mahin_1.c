#include<stdio.h>

int main(){
int a,b,c,d,e,f;
a=6;
int A[a];



printf("Enter the elements:\n");    
for(b=0;b<a;b++){
    scanf("%d",&A[b]);
}



printf("\nElements before deletion:\n");
for(b=0;b<a;b++){
    printf("%d ",A[b]);
}



for(b=2;b<a-1;b++){
    A[b]=A[b+1];
}



printf("\nElements after deletion and before placing a new element at index 4:\n");
for(b=0;b<a-1;b++){
    printf("%d ",A[b]);
}



A[5]=99;      
e=A[5];
A[5]=A[4];
A[4]=e;




printf("\nElements after insertion of the new element:\n");
for(b=0;b<a;b++){
    printf("%d ",A[b]);
}

return 0;}

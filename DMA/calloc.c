//initialize the values stores with 0 unlike malloc which just allocate the memory for the input


#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;
    int n;
    
     printf("enter the value of n : ");

    scanf("%d" ,&n);
    ptr = (int *)calloc(n, sizeof(int));

    for(int i=0; i<n; i++){
        printf("%d\n", ptr[i]);
    }
    
}
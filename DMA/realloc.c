#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;

    ptr = (int*)malloc(5 * sizeof(int));

    printf("enter 5 numbers :");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &ptr[i]);
    }

    ptr = realloc(ptr, 8);
    printf(" now enter 8 numbers :");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < 8; i++)
    {
        printf("numbers %d is %d\n", i,ptr[i]);
    }
    
    

    
}
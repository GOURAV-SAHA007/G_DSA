//it allocates some memory according to the user to enter in runtime and return some pointer memory of void type 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    ptr = (int *)malloc(5 * sizeof(int));

    ptr[0] = 9;
    ptr[1] = 3;
    ptr[2] = 5;
    ptr[3] = 8;
    ptr[4] = 1;

    for(int i = 0; i<5; i++){
        printf("%d\n" ,ptr[i]);
    }
}
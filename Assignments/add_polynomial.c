#include<stdio.h>

void add_poly(int poly1[], int poly2[], int max, int added[]){
    for(int i=0; i<=max; i++){
        added[i] = poly1[i] + poly2[i];
    }
}

void display(int poly[], int max){
    int first = 1;
    for(int i=max; i>=0; i--){
        if(!first){
            printf(" + ");
        }
        printf("%d:%d",poly[i],i);
        first = 0;
    }
    printf("\n");
}

int main(){
    int max = 2;
    int poly1[3] = {0};
    int poly2[3] = {0};
    int added[3] = {0};

    poly1[2] = 52;
    poly1[1] = 27;
    poly1[0] = 88;
    display(poly1, max);

    poly2[2] = 65;
    poly2[1] = 44;
    poly2[0] = 32;
    display(poly2, max);

    add_poly(poly1, poly2, max, added);
    display(added, max);

    return 0;
}
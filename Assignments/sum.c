#include<stdio.h>

int sum(int n){
    if(n==0){
        return 0;
    }else{
        return n + sum(n-1);
    }
}

int printNum(int n, int c){
    printf("%d", c);
    if(c==n){
        return n;
    }else{
        return printNum(n, c+1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printNum(n, 1);
}
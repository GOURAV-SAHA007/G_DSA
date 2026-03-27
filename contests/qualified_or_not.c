#include<stdio.h>

int main(){
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);

    if(n>=2*x && y>=x){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
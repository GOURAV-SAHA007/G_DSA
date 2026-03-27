#include<stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    int results[T];

    for(int t = 0; t < T; t++){
        int n, k;
        scanf("%d %d", &n, &k);
        int stock[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &stock[i]);
        }

        int winning = 0;
        for(int i=0; i<n; i++){
            int buy_price = stock[i];
            for(int j=i+1; j<n; j++){
                int sell_price = stock[j];
                if((sell_price - buy_price) - k > 0){
                    winning++;
                }
            }
        }
        results[t] = winning;
    }

    for(int t = 0; t < T; t++){
        printf("%d\n", results[t]);
    }

}
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int t;
    scanf("%d", &t);
    int results[t];

    for (int test = 0; test < t; test++) {
        int n, c;
        scanf("%d %d", &n, &c);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        qsort(a, n, sizeof(int), compare);

        int minCoins = n;
        for (int k = 0; k < n; k++) {
            int coins = 0;
            for (int i = k; i < n; i++) {
                long long weight = a[i];
                int times = i - k;
                for (int j = 0; j < times; j++) {
                    weight *= 2;
                    if (weight > 1e9) break;
                }
                if (weight > c) coins++;
            }
            if (coins < minCoins) minCoins = coins;
        }

        results[test] = minCoins;
    }

    for (int i = 0; i < t; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}
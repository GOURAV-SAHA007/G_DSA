#include <stdio.h>
#include <string.h>

#define MAXT 10000
#define MAXK 100000
#define MAXLEN 1000000

int main() {
    int t;
    scanf("%d", &t);

    char results[MAXT][MAXLEN];

    for (int tc = 0; tc < t; tc++) {
        long long n;
        int k;
        scanf("%lld %d", &n, &k);

        results[tc][0] = '\0';   // initialize empty string

        if (k == 1) {
            sprintf(results[tc], "%lld", n);
        }
        else if (k % 2 == 1) {
            for (int i = 0; i < k; i++) {
                char temp[50];
                sprintf(temp, "%lld ", n);
                strcat(results[tc], temp);
            }
        }
        else {
            strcat(results[tc], "0 ");
            for (int i = 1; i < k; i++) {
                char temp[50];
                sprintf(temp, "%lld ", n);
                strcat(results[tc], temp);
            }
        }
    }

    for (int i = 0; i < t; i++) {
        printf("%s\n", results[i]);
    }

    return 0;
}

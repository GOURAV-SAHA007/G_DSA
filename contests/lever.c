#include <stdio.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    int results[t];
    for (int tc = 0; tc < t; tc++) {
        int n;
        scanf("%d", &n);
        int a[n], b[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) sum += (a[i] - b[i]);
        }
        results[tc] = (int)(sum + 1);
    }

    for (int i = 0; i < t; i++) {
        printf("%d\n", results[i]);
    }
    return 0;
}

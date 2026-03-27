#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    char (*res)[4] = (char (*)[4])malloc(T * sizeof(*res));
    if (!res) return 0;

    for (int t = 0; t < T; t++) {
        int n;
        scanf("%d", &n);

        int *a = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        int ok = (n == 1);
        if (!ok) {
            qsort(a, n, sizeof(int), cmp_int);
            for (int i = 1; i < n; i++) {
                if (a[i] == a[i - 1]) { ok = 1; break; }
            }
        }

        strcpy(res[t], ok ? "YES" : "NO");

        free(a);
    }

    for (int t = 0; t < T; t++) {
        printf("%s\n", res[t]);
    }

    free(res);
    return 0;
}

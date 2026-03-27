#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *p, const void *q) {
    int a = *(const int*)p;
    int b = *(const int*)q;
    return (a > b) - (a < b);
}

int upper_pref(long long *pref, int n, long long val) {
    int l = 0, r = n + 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (pref[m] <= val) l = m + 1;
        else r = m;
    }
    return l;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    char **results = (char**)malloc(t * sizeof(char*));
    for (int tc = 0; tc < t; ++tc) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        int *a = (int*)malloc(n * sizeof(int));
        int *b = (int*)malloc((n + 1) * sizeof(int));
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        qsort(a, n, sizeof(int), cmp_int);
        long long *pref = (long long*)malloc((n + 1) * sizeof(long long));
        pref[0] = 0;
        for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + (long long)b[i];
        long long best = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && a[i] == a[i-1]) continue;
            int cnt = n - i;
            int idx = upper_pref(pref, n, cnt);
            int levels = idx - 1;
            long long score = (long long)a[i] * (long long)levels;
            if (score > best) best = score;
        }
        char buf[32];
        int len = snprintf(buf, sizeof(buf), "%lld", best);
        results[tc] = (char*)malloc(len + 1);
        memcpy(results[tc], buf, len + 1);
        free(a);
        free(b);
        free(pref);
    }
    for (int tc = 0; tc < t; ++tc) {
        printf("%s\n", results[tc]);
        free(results[tc]);
    }
    free(results);
    return 0;
}
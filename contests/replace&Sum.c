#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    char **results = (char**)malloc(t * sizeof(char*));

    for (int tc = 0; tc < t; ++tc) {
        int n, q;
        if (scanf("%d %d", &n, &q) != 2) return 0;

        int *a = (int*)malloc((n + 2) * sizeof(int));
        int *b = (int*)malloc((n + 2) * sizeof(int));
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);

        int *sufA = (int*)malloc((n + 3) * sizeof(int));
        int *sufB = (int*)malloc((n + 3) * sizeof(int));
        long long *pref = (long long*)malloc((n + 3) * sizeof(long long));

        sufA[n+1] = sufB[n+1] = 0;
        for (int i = n; i >= 1; --i) {
            sufA[i] = a[i] > sufA[i+1] ? a[i] : sufA[i+1];
            sufB[i] = b[i] > sufB[i+1] ? b[i] : sufB[i+1];
        }

        pref[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int val = sufA[i] > sufB[i] ? sufA[i] : sufB[i];
            pref[i] = pref[i-1] + (long long)val;
        }

        int bufsize = q * 20 + 16; 
        results[tc] = (char*)malloc(bufsize);
        int len = 0;

        for (int qi = 0; qi < q; ++qi) {
            int l, r;
            if (scanf("%d %d", &l, &r) != 2) return 0;
            long long ans = pref[r] - pref[l-1];
            if (qi)
                len += snprintf(results[tc] + len, bufsize - len, " %lld", ans);
            else
                len += snprintf(results[tc] + len, bufsize - len, "%lld", ans);
        }
        results[tc][len] = '\0';

        free(a);
        free(b);
        free(sufA);
        free(sufB);
        free(pref);
    }

    for (int tc = 0; tc < t; ++tc) {
        printf("%s\n", results[tc]);
        free(results[tc]);
    }
    free(results);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    char **results = (char**)malloc(t * sizeof(char*));

    for (int tc = 0; tc < t; ++tc) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        int *p = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i) scanf("%d", &p[i]);

        int *sufMax = (int*)malloc(n * sizeof(int));
        int *sufPos = (int*)malloc(n * sizeof(int));

        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                sufMax[i] = p[i];
                sufPos[i] = i;
            } else {
                if (p[i] > sufMax[i+1]) {
                    sufMax[i] = p[i];
                    sufPos[i] = i;
                } else {
                    sufMax[i] = sufMax[i+1];
                    sufPos[i] = sufPos[i+1];
                }
            }
        }

        int done = 0;
        for (int i = 0; i < n && !done; ++i) {
            if (sufMax[i] > p[i]) {
                int l = i, r = sufPos[i];
                while (l < r) {
                    int tmp = p[l]; p[l] = p[r]; p[r] = tmp;
                    ++l; --r;
                }
                done = 1;
            }
        }

        int bufsize = n * 8 + 4; 
        results[tc] = (char*)malloc(bufsize);
        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (i)
                len += snprintf(results[tc] + len, bufsize - len, " %d", p[i]);
            else
                len += snprintf(results[tc] + len, bufsize - len, "%d", p[i]);
        }

        free(p);
        free(sufMax);
        free(sufPos);
    }

    for (int tc = 0; tc < t; ++tc) {
        printf("%s\n", results[tc]);
        free(results[tc]);
    }
    free(results);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    int *out = (int*)malloc(T * sizeof(int));
    for (int tc = 0; tc < T; ++tc) {
        int N, X, K;
        if (scanf("%d %d %d", &N, &X, &K) != 3) return 0;

        int r = X % K;
        int ans = X;

        if (r < ans) ans = r;

        if (X + (K - r) <= N) {
            if (K - r < ans)
                ans = K - r;
        }

        out[tc] = ans;
    }

    for (int tc = 0; tc < T; ++tc) {
        printf("%d\n", out[tc]);
    }

    free(out);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    int *out = (int*)malloc(T * sizeof(int));
    for (int tc = 0; tc < T; ++tc) {
        int X, Y, Z;
        if (scanf("%d %d %d", &X, &Y, &Z) != 3) return 0;
        int pairs = (X < Z ? X : Z) + (Y / 2);
        out[tc] = pairs;
    }
    for (int tc = 0; tc < T; ++tc) {
        printf("%d\n", out[tc]);
    }
    free(out);
    return 0;
}
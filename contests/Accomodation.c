#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long ceil_div(long long a, long long b) {
    if (b <= 0) {
        if (a == 0) return 0;
        return LLONG_MAX / 4;
    }
    return (a + b - 1) / b;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    long long *out = (long long*)malloc((size_t)t * sizeof(long long));
    for (int tc = 0; tc < t; ++tc) {
        long long B, G, X, Y, N;
        if (scanf("%lld %lld %lld %lld %lld", &B, &G, &X, &Y, &N) != 5) return 0;

        long long A = ceil_div(B, N - Y); 
        long long C = ceil_div(G, N - X); 
        long long D = ceil_div(B + G, N);

        long long L = A;
        if (C > L) L = C;
        if (D > L) L = D;

        long long UB1 = (X > 0) ? (B / X) : LLONG_MAX / 4;
        long long UB2 = (Y > 0) ? (G / Y) : LLONG_MAX / 4;
        long long U = UB1 < UB2 ? UB1 : UB2;

        if (L <= U) out[tc] = L;
        else out[tc] = -1;
    }

    for (int tc = 0; tc < t; ++tc) {
        printf("%lld\n", out[tc]);
    }
    free(out);
    
    return 0;
}
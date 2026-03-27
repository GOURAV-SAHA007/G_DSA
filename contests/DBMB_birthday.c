#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    char results[T][4];

    for (int tc = 0; tc < T; ++tc) {
        int n;
        long long s, x;
        if (scanf("%d %lld %lld", &n, &s, &x) != 3) return 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            if (scanf("%lld", &a) != 1) return 0;
            sum += a;
        }
        if (s >= sum && (s - sum) % x == 0) {
            strcpy(results[tc], "YES");
        } else {
            strcpy(results[tc], "NO");
        }
    }

    for (int tc = 0; tc < T; ++tc) {
        printf("%s\n", results[tc]);
    }

    return 0;
}
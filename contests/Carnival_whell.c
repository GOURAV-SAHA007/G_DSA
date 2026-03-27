#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    scanf("%d", &t);

    int res[t];

    for (int tc = 0; tc < t; tc++) {
        int l, a, b;
        scanf("%d %d %d", &l, &a, &b);

        int g = gcd(l, b);

        int cur = a;
        int maxPrize = a;

        while (1) {
            cur = (cur + g) % l;   // move wheel

            if (cur == a)          // cycle completed
                break;

            if (cur > maxPrize)
                maxPrize = cur;
        }

        res[tc] = maxPrize;
    }

    for (int i = 0; i < t; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}

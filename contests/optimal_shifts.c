#include <stdio.h>
#include <string.h>

#define MAXN 200005

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char s[MAXN];
        scanf("%s", s);

        int maxZeros = 0, cur = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cur++;
                if (cur > maxZeros) maxZeros = cur;
            } else {
                cur = 0;
            }
        }

        int prefix = 0;
        for (int i = 0; i < n && s[i] == '0'; i++) prefix++;

        int suffix = 0;
        for (int i = n-1; i >= 0 && s[i] == '0'; i--) suffix++;

        if (prefix + suffix > maxZeros && prefix + suffix < n) {
            maxZeros = prefix + suffix;
        }

        printf("%d\n", maxZeros);
    }

    return 0;
}

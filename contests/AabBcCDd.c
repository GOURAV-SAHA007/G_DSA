#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    int *out = (int*)malloc(t * sizeof(int));
    for (int tc = 0; tc < t; ++tc) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        char s[105];
        if (scanf("%s", s) != 1) return 0;
        int cnt[26] = {0};
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') cnt[s[i]-'a']++;
            else if (s[i] >= 'A' && s[i] <= 'Z') cnt[s[i]-'A']++;
        }
        int max1 = 0, max2 = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > max1) { max2 = max1; max1 = cnt[i]; }
            else if (cnt[i] > max2) { max2 = cnt[i]; }
        }
        out[tc] = max1 + max2;
    }
    for (int tc = 0; tc < t; ++tc) {
        printf("%d\n", out[tc]);
    }
    free(out);
    return 0;
}
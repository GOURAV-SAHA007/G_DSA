#include <stdio.h>
#include <string.h>

void reverse(char* s, int i, int j) {
    if (i >= j) return;  // base case

    // swap characters
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    // recursive call
    reverse(s, i + 1, j - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    reverse(s, 0, n - 1);
    printf("%s\n", s);

    return 0;
}

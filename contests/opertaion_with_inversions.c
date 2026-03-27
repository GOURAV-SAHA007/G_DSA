#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int mx = a[0];
        int count = 0;

        for (int i = 1; i < n; i++) {
            if (a[i] < mx) {
                count++;       
            } else {
                mx = a[i];     
            }
        }

        printf("%d\n", count);
    }

    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int isSorted = 1;

        for (int i = 0; i < n - 1; i++) {
            // Using math.h min function
            int minVal = fmin(arr[i], arr[i + 1]);

            // Perform operation if needed (not actually required in logic)
            arr[i] -= minVal;
            arr[i + 1] -= minVal;

            if (arr[i] > arr[i + 1]) {
                isSorted = 0;
                break;
            }
        }

        if (isSorted)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

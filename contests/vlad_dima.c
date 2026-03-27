#include <stdio.h>
#include <string.h>

void append_end(char *a, char b) {
    int len = strlen(a);
    a[len] = b;
    a[len + 1] = '\0';
}

void append_start(char *a, char b) {
    int len = strlen(a);
    for (int i = len; i >= 0; i--) {
        a[i + 1] = a[i];
    }
    a[0] = b;
}

int main() {
    int T;
    scanf("%d", &T);
    getchar(); 

    char results[T][1000]; 

    for (int t = 0; t < T; t++) {
        int a, b;
        char A[1000], B[1000], DV[1000];
        scanf("%d", &a);
        scanf("%s", A);
        getchar(); 

        scanf("%d", &b);
        scanf("%s", B);
        getchar();
        scanf("%s", DV);

        for (int i = 0; i < b; i++) {
            if (DV[i] == 'D') {
                append_end(A, B[i]);
            } else {
                append_start(A, B[i]);
            }
        }
        strcpy(results[t], A); 
    }

    for (int i = 0; i < T; i++) {
        printf("%s\n", results[i]);
    }

    return 0;
}

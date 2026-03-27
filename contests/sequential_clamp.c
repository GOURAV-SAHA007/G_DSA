#include <stdio.h>
#include <stdlib.h>

int main(){
    int T;
    if (scanf("%d", &T) != 1) return 0;

    int *answers = (int*)malloc(T * sizeof(int));
    if (!answers) return 0;

    for (int tc = 0; tc < T; ++tc) {
        int N;
        if (scanf("%d", &N) != 1) return 0;

        int Y = 1000000000; 
        for (int i = 0; i < N; ++i) {
            int A, B;
            if (scanf("%d %d", &A, &B) != 2) return 0;
            if (Y < A) Y = A;
            else if (Y > B) Y = B;
        }
        answers[tc] = Y;
    }

    for (int tc = 0; tc < T; ++tc) {
        printf("%d\n", answers[tc]);
    }

    free(answers);
    return 0;
}
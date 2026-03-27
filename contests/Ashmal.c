#include <stdio.h>
#include <string.h>

#define MAXT 500
#define MAXLEN 5000

int main() {
    int t;
    scanf("%d", &t);

    char results[MAXT][MAXLEN];

    for (int tc = 0; tc < t; tc++) {
        int n;
        scanf("%d", &n);

        char s[MAXLEN];
        s[0] = '\0';   

        for (int i = 0; i < n; i++) {
            char ai[4005];
            scanf("%s", ai);

            char front[MAXLEN];
            char back[MAXLEN];

            strcpy(front, ai);
            strcat(front, s);

            strcpy(back, s);
            strcat(back, ai);

            if (strcmp(front, back) < 0) {
                strcpy(s, front);
            } else {
                strcpy(s, back);
            }
        }

        strcpy(results[tc], s);
    }

    for (int i = 0; i < t; i++) {
        printf("%s\n", results[i]);
    }

    return 0;
}

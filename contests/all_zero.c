#include <stdio.h>

int main()
{
    int T;
    if (scanf("%d", &T) != 1)
        return 0;
    const char *results[T];

    for (int t = 0; t < T; t++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int y = b - 2 * a;
        if (y >= 0 && c == 3 * y)
        {
            results[t] = "Yes";
        }
        else
        {
            results[t] = "No";
        }
    }

    for(int t = 0; t < T; t++)
    {
        printf("%s\n", results[t]);
    }

    return 0;
}

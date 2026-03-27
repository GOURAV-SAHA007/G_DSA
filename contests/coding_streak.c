#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    int results[T];

    for (int t = 0; t < T; t++)
    {

        int n;
        scanf("%d", &n);

        int days[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &days[i]);
        }

        int max_streak = 0;
        int current_streak = 0;

        for (int i = 0; i < n; i++)
        {

            if (days[i] != 0)
            {
                current_streak++;

                if (current_streak > max_streak)
                {
                    max_streak = current_streak;
                }
            }
            else
            {
                current_streak = 0;
            }
            results[t] = max_streak;
        }
    }
    for (int t = 0; t < T; t++)
    {
        printf("%d\n", results[t]);
    }
    return 0;
}
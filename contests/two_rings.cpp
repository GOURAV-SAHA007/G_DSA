#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            long long x1, y1, r1;
            long long x2, y2, r2;
            cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

            long long dx = x1 - x2;
            long long dy = y1 - y2;
            long long d_squared = dx * dx + dy * dy;

            long long r_sum_squared = (r1 + r2) * (r1 + r2);
            long long r_diff_squared = (r1 - r2) * (r1 - r2);

            if (d_squared > r_sum_squared)
            {
                cout << "No\n";
            }
            else if (d_squared < r_diff_squared)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}
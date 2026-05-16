#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;

    while (t--)
    {
        long long n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;

        long long straight_dist = abs(x1 - x2);
        long long circular_dist = n - straight_dist;

        long long shortest_dist = min(straight_dist, circular_dist);

        long long ans = shortest_dist + k;

        ans = min(ans, n - 1);

        cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            cin >> n;

            unordered_map<int, int> freq;
            int max_freq = 0;

            for (int i = 0; i < n; i++)
            {
                int val;
                cin >> val;
                freq[val]++;
                max_freq = max(max_freq, freq[val]);
            }

            int distinct_scores = n - max_freq + 1;
            cout << distinct_scores << "\n";
        }
    }
    return 0;
}
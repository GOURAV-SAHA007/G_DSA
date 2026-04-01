#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<int> temps(N);
        for (int i = 0; i < N; ++i) cin >> temps[i];

        if (N <= 2) {
            cout << 0 << '\n';
            continue;
        }

        int mn = *min_element(temps.begin(), temps.end());
        int mx = *max_element(temps.begin(), temps.end());

        int liked = 0;
        for (int t : temps) if (t != mn && t != mx) ++liked;
        cout << liked << '\n';
    }
    return 0;
}
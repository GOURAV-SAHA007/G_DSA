#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string s;
    cin >> s;

    vector<int> miss_indices;
    miss_indices.reserve(n);

    vector<int> pref_hits(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pref_hits[i] = pref_hits[i - 1] + (s[i - 1] == 'o' ? 1 : 0);
        if (s[i - 1] == 'x') {
            miss_indices.push_back(i);
        }
    }

    int total_misses = miss_indices.size();

    for (int k = 1; k <= n; k++) {
        int hk = pref_hits[k];

        if (hk == 0) {
            cout << k << "\n";
            continue;
        }

        int max_allowed_misses = k;

        if (max_allowed_misses >= total_misses) {
            cout << n << "\n";
        } else {
            int stopping_miss_index = miss_indices[max_allowed_misses];
            cout << stopping_miss_index - 1 << "\n";
        }
    }

    return 0;
}
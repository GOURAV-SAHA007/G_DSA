#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bitset<20001> reachable; 
    reachable[0] = 1;

    vector<int> result;
    vector<bool> used(n, false);

    for (int i = 0; i < n; i++) {
        int best_idx = -1;

        for (int j = 0; j < n; j++) {
           
            if (!used[j] && !reachable[a[j]]) {
                if (best_idx == -1 || a[j] > a[best_idx]) {
                    best_idx = j;
                }
            }
        }

        if (best_idx == -1) {
            cout << -1 << endl;
            return;
        }

        int val = a[best_idx];
        used[best_idx] = true;
        result.push_back(val);

        reachable |= (reachable << val);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
         int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        auto get_comb = [&](int n, int k) {
            if (k < 0 || k > n) return 0;
            if ((n & k) == k) return 1;
            return 0;
        };

        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (get_comb(n - 1, i)) {
                result ^= a[i];
            }
        }
        cout << result << "\n";
    }
    return 0;
}
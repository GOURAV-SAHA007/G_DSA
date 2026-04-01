#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        unordered_map<long long, long long> cnt;
        cnt.reserve(N * 2);
        for (int i = 0; i < N; ++i) {
            long long key = A[i] - (i + 1); // Ai - i
            ++cnt[key];
        }

        long long ans = 0;
        for (auto &p : cnt) {
            long long c = p.second;
            ans += c * (c - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
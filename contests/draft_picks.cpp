#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long N, K;
        cin >> N >> K;

        if (N == 1) {
            cout << (K * (K + 1) / 2) << '\n';
            continue;
        }

        long long L = 2 * N - 2;             
        long long full = K / L;              
        long long rem  = K % L;              
        vector<long long> sum(N, 0);

        for (long long pos = 0; pos < L; ++pos) {
            long long cnt = full + (pos < rem ? 1 : 0);
            if (cnt == 0) continue;

            long long first = K - pos; 
            long long total_at_pos = cnt * first - L * (cnt * (cnt - 1) / 2);

            long long player = (pos < N) ? pos : (2 * N - 2 - pos); 
            sum[player] += total_at_pos;
        }

        cout << *max_element(sum.begin(), sum.end()) << '\n';
    }
    return 0;
}
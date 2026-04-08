#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> arr(N, vector<int>(3));
        for (int i = 0; i < N; i++) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        }
        vector<pair<int,int>> all; 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                all.push_back({arr[i][j], i});
            }
        }

        sort(all.begin(), all.end());
        int total = 0;
        vector<int> count(N, 0);
        int ans = INT_MAX;
        int l = 0;

        for (int r = 0; r < (int)all.size(); r++) {
            if (count[all[r].second] == 0) total++;
            count[all[r].second]++;

            while (total == N) {
                ans = min(ans, all[r].first - all[l].first);
                count[all[l].second]--;
                if (count[all[l].second] == 0) total--;
                l++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

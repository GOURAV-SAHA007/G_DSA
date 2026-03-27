#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    vector<string> results;
    results.reserve(T);

    for (int i = 0; i < T; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        int passes = (x >= 50) + (y >= 50) + (z >= 50);
        results.push_back(passes >= 2 ? "Yes" : "No");
    }

    for (const auto &r : results) cout << r << '\n';
    return 0;
}
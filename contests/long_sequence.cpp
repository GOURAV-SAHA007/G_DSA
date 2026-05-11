#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> b;
    for (int i = 0; i < n; i++) {
        int times = c[i];
        while (times--) {
            for (int j = 0; j < a[i].size(); j++) {
                b.push_back(a[i][j]);
            }
        }
    }

    cout << b[k-1] << endl;

    return 0;
}
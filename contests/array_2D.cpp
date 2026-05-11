#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m; 
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int x, y;
    if (cin >> x >> y) {
        cout << a[x-1][y-1] << endl;
    }

    return 0;
}
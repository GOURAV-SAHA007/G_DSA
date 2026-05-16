#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, z;
    if (!(cin >> x >> y >> z)) return 0;
    int australia_total = x + z;
    int target = australia_total + 1;
    int runs_needed = target - y;
    if (runs_needed < 0) {
        cout << 0 << endl;
    } else {
        cout << runs_needed << endl;
    }

    return 0;
}
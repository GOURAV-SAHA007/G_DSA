#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        int max_side = max({x, y, z});
        int total_sum = x + y + z;
        
        int sum_small = total_sum - max_side;

        if (sum_small > max_side) {
            cout << 0 << "\n";
        } else {
            cout << (max_side + 1) - sum_small << "\n";
        }
    }
    return 0;
}
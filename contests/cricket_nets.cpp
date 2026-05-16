#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
    cin >> x;
    int total_cost = 0;
    if (x<=20) {
        total_cost = x * 10;
    } else {
        int p1 = 20 * 10;
        
        int remaining_runs = x - 20;
        int phase2_balls = remaining_runs / 2;
        int phase2_cost = phase2_balls * 5;
        
        total_cost = p1 + phase2_cost;
    }

    cout << total_cost << endl;
    }
    return 0;
}
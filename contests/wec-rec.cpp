#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x, k;
    cin >> n >> x >> k;
    map<int, int> clusters;
    for (int i=0; i<n; i++) {
        int score;
        cin >> score;
        clusters[score]++;
    }
    vector<int> counts;
    for (auto const& [score, count] : clusters) {
        counts.push_back(count);
    }
    reverse(counts.begin(), counts.end());

    int selected = 0;
    int limit = min((int)counts.size(), k);  
    for (int i = 0; i < limit; i++) {
        selected+=counts[i];
    }
    cout <<min(selected, x) << endl;
    }
    
    return 0;
}
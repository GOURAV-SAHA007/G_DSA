#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int p;
        cin >> p;
        p--; 
        
        int x = a[p];
        
        int left_segments = 0;
        bool in_segment = false;
        for (int i = 0; i < p; i++) {
            if (a[i] != x) {
                if (!in_segment) {
                    left_segments++;
                    in_segment = true;
                }
            } else {
                in_segment = false;
            }
        }
        
        int right_segments = 0;
        in_segment = false;
        for (int i = p + 1; i < n; i++) {
            if (a[i] != x) {
                if (!in_segment) {
                    right_segments++;
                    in_segment = true;
                }
            } else {
                in_segment = false;
            }
        }
        
        int answer = 2 * max(left_segments, right_segments);
        cout << answer << "\n";
    }
    return 0;
}
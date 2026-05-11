#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n, x;
        cin >> n >> x;

        int max_candi = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a; 
            
            if (a % x == 0) {
                if (a > max_candi) {
                    max_candi = a;
                }
            }
        }
        cout << max_candi << "\n";
    }
    return 0;
}
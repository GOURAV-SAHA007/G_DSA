#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, X;
    cin >> T >> X;

    vector<int> A(T+1);
    for (int i = 0; i <= T; i++) cin >> A[i];

    int last_saved = A[0];
    cout << 0 << " " << A[0] << endl;

    for (int i = 1; i <= T; i++) {
        if (abs(A[i] - last_saved) >= X) {
            cout << i << " " << A[i] << endl;
            last_saved = A[i];  
        }
    }

    return 0;
}

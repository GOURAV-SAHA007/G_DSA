#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long A, B, C;
        cin >> A >> B >> C;
        if (A == B) {
            cout << 0 << '\n';
            continue;
        }
        if (std::gcd(A, C) == std::gcd(B, C)) {
            cout << 1 << '\n';
            continue;
        }
        if (std::gcd(A, C + 1) == std::gcd(B, C + 1)) {
            cout << 2 << '\n';
            continue;
        }
        cout << 3 << '\n';
    }
    return 0;
}
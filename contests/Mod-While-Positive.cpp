#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    if (cin >> n >> m) {
        int operations = 0;
        while (m!= 0) {
            int remainder = n % m;  
            m = remainder;
            operations++;
        }
        cout << operations << "\n";
    }

    return 0;
}
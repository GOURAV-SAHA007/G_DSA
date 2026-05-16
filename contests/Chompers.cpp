#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    
    if (cin >> s >> n) {
        string result = s.substr(n, s.length() - 2 * n);
        cout << result << "\n";
    }

    return 0;
}
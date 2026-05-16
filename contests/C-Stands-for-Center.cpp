#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        long long total_substrings = 0;
        long long len = s.length();

        for (long long i = 0; i < len; i++) {
            if (s[i] == 'C') {
                long long left_chars = i;
                long long right_chars = len - 1 - i;
                total_substrings += min(left_chars, right_chars) + 1;
            }
        }

        cout << total_substrings << "\n";
    }

    return 0;
}
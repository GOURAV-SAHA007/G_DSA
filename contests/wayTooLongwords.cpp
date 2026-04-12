#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    if (!(cin >> n)) return 0;

    vector<string> results(n);
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        if (word.length() > 10) {
            int len = static_cast<int>(word.length()) - 2;
            results[i] = string(1, word.front()) + to_string(len) + string(1, word.back());
        } else {
            results[i] = word;
        }
    }

    for (const auto &s : results) cout << s << '\n';
    return 0;
}
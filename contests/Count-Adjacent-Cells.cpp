#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    if (cin >> h >> w) {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                int count = 0;
                if (i - 1 >= 1) count++;
                if (i + 1 <= h) count++;
                if (j - 1 >= 1) count++;
                if (j + 1 <= w) count++;
                cout << count << (j == w ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}
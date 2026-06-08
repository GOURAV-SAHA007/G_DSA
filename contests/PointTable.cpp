#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y, a, b;
    if (cin >> x >> y >> a >> b) {
        if (x > a || (x == a && y >= b)) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}
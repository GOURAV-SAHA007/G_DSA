#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int count_a = 0;
        int count_b = 0;

        for (char c : s) {
            if (c == 'a') count_a++;
            else if (c == 'b') count_b++;
        }

        cout << count_a << count_b << endl;
    }
    return 0;
}
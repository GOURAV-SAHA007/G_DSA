#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n, m;
        cin >> n >> m;

        if((n+1) % 3 != 0){
            cout << -1 << endl;
            continue; 
        }

        long long x = m / 2 + 1;

        for(int i = 1; i <= n; i++){
            int rem = i % 6;
            if(rem == 1 || rem == 2){
                cout << x;
            } else if(rem == 3 || rem == 0){
                cout << 0;
            } else {
                cout << (m - x) % m;
            }

            if(i < n){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
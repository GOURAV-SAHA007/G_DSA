#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;

        int min_cost;
        int combo = min(n, m) * c;
        int extra_cost = 0;
        if(n > m){
            extra_cost = (n - m) * a;
        }else if(m > n){
            extra_cost = (m - n) * b;
        }

        min_cost = combo + extra_cost;

        cout << min_cost << endl;
    }

    return 0;
}
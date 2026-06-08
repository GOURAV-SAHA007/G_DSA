#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int min_cost = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] == a[j]){
                    int curr_cost = i + (n - 1 - j);         
                    if(curr_cost < min_cost){
                        min_cost = curr_cost;
                    }
                }
            }
        }
        
        if(min_cost == INT_MAX){
            cout << -1 << "\n";
        }else{
            cout << min_cost << "\n";
        }
    }
    return 0;
}
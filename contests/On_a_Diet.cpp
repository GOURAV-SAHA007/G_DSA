#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<bool> ate(n, false);
    vector<string> res(n);

    long long totalCalorie = 0;

    for(int i=0; i<n; i++){
        if(i>=m && ate[i-m]){
            totalCalorie -= a[i-m];
        }

        if(totalCalorie+a[i] <= k){
            ate[i] = true;
            totalCalorie += a[i];
            res[i] = "Yes";
        }else{
            res[i] = "No";
        }
    }

    for(int i=0; i<n; i++){
        cout << res[i] << endl;
    }

    return 0;
}
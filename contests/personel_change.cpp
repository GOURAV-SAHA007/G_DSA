#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> curr(m+1, 0);
    vector<int> next(m+1, 0);

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        curr[a]++;
        next[b]++;
    }

    for(int j=1; j<=m; j++){
        cout << next[j]-curr[j] << endl;
    }

     return 0;
}
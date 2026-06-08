#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    //  USING HASHING
    // vector<int> hash(n+1, 0);

    // for(int i=0; i<n; i++){
    //     hash[a[i]]++;
    // }

    // for(int i=1; i<=n; i++){
    //     if(hash[i]==1){
    //         cout << i << " ";
    //     }
    // }

    //      USING MAP
    // map<long long, int> mpp;

    // for(int i=0; i<n; i++){
    //     mpp[a[i]]++;
    // }

    // for(auto it:mpp){
    //     if(it.second==1){
    //         cout << it.first << " ";
    //     }
    // }

    //OPTIMAL SOLUTION
    // XOR approach
    int xor1 = 0;
    for(int i=0; i<n; i++){
        xor1 ^= a[i];
    }
    cout << xor1 << " ";

    return 0;
}
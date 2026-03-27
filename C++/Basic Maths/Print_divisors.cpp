#include<bits/stdc++.h>
using namespace std;

// 2 Methods

int main(){
    int n;
    cin >> n;

    //Brute Force O(N)
    // for(int i=1; i<=n; i++){
    //     if(n%i==0){
    //         cout << i << " ";
    //     }
    // }

    //O(sqrtN) approach
    vector<int>ls;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            ls.push_back(i);
            if((n/i)!=i){
                ls.push_back(n/i);
            }
        }
    }

    sort(ls.begin(), ls.end());
    for(auto it:ls){
        cout << it << " ";
    }

    return 0;
}
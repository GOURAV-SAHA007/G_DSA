#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int cm = n/2+1;
    if(cm <= k){
        cout << 0 << endl;
        return 0;
    }else{
        cout << cm - k << endl;
    }
    return 0;
}
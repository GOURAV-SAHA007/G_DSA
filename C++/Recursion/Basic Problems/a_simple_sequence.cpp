#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int n;
        cin >> n;
        for(int i=n; i>=1; i--){
            cout << i;
            if(i>1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    int result[T];
    for(int t=0; t<T; t++){
        int n;
        cin >> n;
        int m = n+1;
        if(m > 67) m = n;
        result[t] = m;
    }

    for(int t=0; t<T; t++){
        cout << result[t] << endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    int result[T];
    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        if((n%2==0 && n%5!=0) || (n%2!=0 && n%5==0)){
            result[t] = 0;
            continue;
        }

        int min_diff = INT_MAX;
        for(int i=0; ; i++){
            int m = n-i;
            if(m>0 && m%2==0 && m%10!=0){
                min_diff = min(min_diff, abs(n-m));
                break;
            }

            m = n+i;
            if(m%2==0 && m%10!=0){
                min_diff = min(min_diff, abs(n-m));
                break;
            }
        }

        for(int i=0; ; i++){
            int m = n-i;
            if(m>0 && m%5==0 && m%2!=0){
                min_diff = min(min_diff, abs(n-m));
                break;
            }

            m = n+i;
            if(m%5==0 && m%2!=0){
                min_diff = min(min_diff, abs(n-m));
                break;
            }
        }

        result[t] = min_diff;
    }

    for(int t=0; t<T; t++){
        cout << result[t] << endl;
    }

    return 0;
}
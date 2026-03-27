#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    long long result[T][2] = {0};
    for(int t=0; t<T; t++){
        long long n, m;
        cin >> n >> m;
        bool found = false;

        if(m < n){
            result[t][0] = m;
            result[t][1] = m+1;
            found = true;
        }

        if(!found){
            for(long long i=1; i<=1000000000LL; i=i*2+1){
                if(i==1){
                    if(m>=1 && m<=n){
                        result[t][0] = 1;
                        result[t][1] = m;
                        found = true;
                        break;
                    }
                    continue;
                }

                for(long long y=0; y<=n; y++){
                    long long xval = i * y - m;
                    long long x = xval / (i-1);
                    if(xval % (i-1) == 0 && xval >= 0){
                        if(x < y && x > 0){
                            result[t][0] = x;
                            result[t][1] = y;
                            found = true;
                            break;
                        }
                    }
                }
                if(found) break;
            }
        }
        if(!found) result[t][0] = -1;
    }

    for(int t=0; t<T; t++){
        if(result[t][0] == -1){
            cout << -1 << endl;
        } else {
            cout << result[t][0] << " " << result[t][1] << endl;
        }
    }

    return 0;
}
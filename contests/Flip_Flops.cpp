#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    long long result[T];
    for(int t=0; t<T; t++){
        int n;
        long long c, k;
        cin >> n >> c >> k;

        vector<long long> monster(n);
        for(int i=0; i<n; i++){
            cin >> monster[i];
        }

        sort(monster.begin(), monster.end());

        for(int i=0; i<n; i++){
            if(monster[i] <= c){
                c = c+monster[i];
            }else{
                if(monster[i]+k <= c){
                    c = c+monster[i]+k;
                    k = 0;
                }else{
                    break;
                }
            }
        }

        result[t] = c;
    }

    for(int t=0; t<T; t++){
        cout << result[t] << endl;
        }
    return 0;
}
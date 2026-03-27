#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    int result[T];
    for(int t=0; t<T; t++){
        int n, k;
        cin >> n >> k;
        vector<int> cost(n), tastiness(n);
        for(int i=0; i<n; i++) cin >> cost[i];
        for(int i=0; i<n; i++) cin >> tastiness[i];

        int max_tastiness = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int c1 = cost[i];
                int c2 = cost[j];
                int t1 = tastiness[i];
                int t2 = tastiness[j];
                if(c1>c2){
                    swap(c1, c2);
                    swap(t1, t2);
                }
                int discount = min(c2/2, 100);
                int total_cost = c1 + (c2 - discount);
                if(total_cost <= k){
                    int taste = t1+t2;
                    if(taste > max_tastiness){
                        max_tastiness = taste;
                    }
                }
            }
        }
        result[t] = max_tastiness;
    }

    for(int t=0; t<T; t++){
        cout << result[t] << endl;
    }

    return 0;
}
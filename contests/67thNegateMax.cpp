#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    int result[T];
    for(int t=0; t<T; t++){
        int n = 7;
        
        vector<int> arr(n);
        int sum_all = 0;
        int max_a = INT_MIN;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum_all += arr[i];
            if(arr[i] > max_a) max_a = arr[i];
        }

        result[t] = 2 * max_a - sum_all;
    }

    for(int t=0; t<T; t++){
        cout << result[t] << endl;
    }
    return 0;
}
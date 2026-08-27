#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 6, 7, 5, 7};
    int n = arr.size();

    // vector<int> mpp(n+1, 0);
    // vector<int> res;

    // for(int i=0; i<n+1; i++){
    //     mpp[arr[i]]++;
    // } 

    // for(int i=0; i<n+1; i++){
    //     if(mpp[i]==2){
    //         res.push_back(i);
    //     }else if(mpp[i]==0){
    //         res.push_back(i);
    //     }
    // }

    // cout << res[0] << " " << res[1];

    int sumN = n*(n+1) / 2;
    int sum2N = n*(n+1)*(2*n+1) / 6;
    int sumArr = {0};
    int sum2Arr = {0}; 

    for(int i=0; i<n; i++){
        sumArr += arr[i];
        sum2Arr += (arr[i]*arr[i]);
    }

    int val1 = sumN-sumArr;
    int val2 = sum2N-sum2Arr;

    val2 = val2/val1;

    int repeating = (val2 - val1) / 2;
    int missing = (val2 + val1) / 2;

    cout << repeating << " " << missing;

    return 0;
}
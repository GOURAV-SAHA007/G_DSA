#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int k;
    cin >> k;

    //      BRUTE FORCE
    // int max_length = 0;
    // for(int i=0; i<n; i++){
    //     int sum =0;
    //     for(int j=i; j<n; j++){
    //         sum = sum + a[j];
    //         if(sum == k){
    //             max_length = max(max_length, j-i+1);
    //         }
    //     }
    // }
    // cout << max_length << endl;

    //       BETTER APPROACH
    // map<long long, int> prefixSum;\
    // int sum = 0;
    // int max_length = 0;
    // for(int i=0; i<n; i++){
    //     sum += a[i];
    //     if(sum==k){
    //         max_length = max(max_length, i+1);
    //     }
    //     int rem = sum-k;
    //     if(prefixSum.find(rem)!=prefixSum.end()){
    //         int len = i-prefixSum[rem];
    //         max_length = max(max_length, len);
    //     }
    //     if(prefixSum.find(sum)==prefixSum.end()){
    //         prefixSum[sum]=i;
    //     }
    // }

    //      OPTIMAL SOLUTION
    int left=0; 
    int right =0;
    int max_length = 0;
    int sum = a[0];
    
    while(right < n){
        if(left<right && sum > k){
            sum -= a[left];
            left++;
        }

        if(sum == k){
            max_length = max(max_length, right-left+1);
        }
        right++;

        if(right < n){
            sum +=a[right];
        }
    }
    cout << max_length << endl;
    return 0;
}
    

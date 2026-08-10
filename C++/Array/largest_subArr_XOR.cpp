#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {5, 6, 7, 8, 9};
    int n = nums.size();

    int b;
    cin >> b;

    // int count = 0;

    // for (int i = 0; i < n; i++){
    //     int xorVal = 0;
    //     for(int j=i; j<n; j++){
    //         xorVal ^= nums[j];
    //         if(xorVal==b){
    //             count++;
    //         }
    //     }
    // }
    // cout << count << endl;

    int xorVal = 0;
    map<int, int> mpp;
    mpp[xorVal]++;
    int cnt = 0;

    for(int i=0; i<n; i++){
        xorVal ^= nums[i];
        int x = xorVal ^ b;
        cnt += mpp[x];
        mpp[xorVal]++;
    }
    cout << cnt << endl;
    return 0;
}
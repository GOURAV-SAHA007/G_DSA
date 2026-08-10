#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {6, -2, 2, -8, 1, 7, 4, -10};
    int n = nums.size();

    unordered_map<int, int> mpp;
    
    int sum = 0;
    int maxLen = 0;

    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum==0){
            maxLen = i+1;
        }else{
            if(mpp.find(sum) != mpp.end()){
                maxLen = max(maxLen, i-mpp[sum]);
            }else{
                mpp[sum] = i;
            }
        }
    }
    cout << maxLen << endl;
    return 0;
}
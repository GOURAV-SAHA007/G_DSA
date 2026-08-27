#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums = {-1, 0, 1, 2, -1, -4};
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for(int i=0; i<n-2; i++){
        int left = i+1;
        int right = n-1;

        if(i>0 && nums[i]==nums[i-1]) continue;

        while(left<right){
            int sum = nums[i]+nums[left]+nums[right];
            if(sum==0){
                res.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                while(left<right && nums[left]==nums[left-1]) left++;
                while(left<right && nums[right]==nums[right+1]) right--;
            }else if(sum>0){
                right--;
            }else{
                left++;
            }
        }
    }

    for(int i = 0; i < res.size(); i++){
        cout << "[";
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j];
            if(j < res[i].size()-1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;    return 0;
}
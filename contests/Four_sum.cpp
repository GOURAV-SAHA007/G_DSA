#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>&nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;

    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int left = j+1;
            int right = n-1;
            while(left < right){
                int sum = nums[i]+nums[j]+nums[left]+nums[right];
                if(sum==target){
                    vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                    while(left<right && nums[left]==nums[left+1])left++;
                    while(left<right && nums[right]==nums[right-1])right--;
                    res.push_back(temp);
                    left++;
                    right--;
                }else if(sum>target){
                    right--;
                }else{
                    left++;
                }
            }
            
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0; i<n; i++)cin >> nums[i];
    
    fourSum(nums, 5);

    return 0;
}
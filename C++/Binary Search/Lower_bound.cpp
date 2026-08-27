#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int &target){
    int n = nums.size();

    int left = 0;
    int right = n-1;
    int ans = n;
    while(left<=right){
        int mid = left + right / 2;
        if(nums[mid]>=target){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {3,5,8,15,19};
    int target = 9;

    int lb = binarySearch(nums, target);

    cout << lb << endl;
    return 0;
}
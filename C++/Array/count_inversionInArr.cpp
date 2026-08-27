#include <bits/stdc++.h>
using namespace std;

long long mergeSort(vector<int>& nums, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;

    long long count = 0;

    vector<int> temp;

    while (left <= mid && right <= high) {

        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            // nums[right] is smaller than all remaining
            // elements in the left half.
            count += (mid - left + 1);

            temp.push_back(nums[right]);
            right++;
        }
    }

    // Remaining elements of left half
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    // Remaining elements of right half
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // Copy sorted elements back
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }

    return count;
}

long long merge(vector<int>& nums, int low, int high) {

    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += merge(nums, low, mid);
    count += merge(nums, mid + 1, high);

    count += mergeSort(nums, low, mid, high);

    return count;
}

long long numberOfInv(vector<int>& nums) {

    int n = nums.size();

    return merge(nums, 0, n - 1);
}

int main() {

    vector<int> nums = {5, 3, 2, 1, 4};

    long long count = numberOfInv(nums);

    cout << count << endl;

    return 0;
}
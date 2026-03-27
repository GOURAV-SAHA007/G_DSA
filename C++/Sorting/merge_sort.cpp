#include<bits/stdc++.h>
using namespace std;

void merged(vector <int>& arr, int left, int mid, int right){
    vector<int>temp;

    int l = left;
    int r = mid+1;

    while(l <= mid && r <= right){
        if(arr[l] <= arr[r]){
            temp.push_back(arr[l]);
            l++;
        }else{
            temp.push_back(arr[r]);
            r++;
        }
    }

    while(l <= mid){
        temp.push_back(arr[l]);
        l++;
    }

    while(r <= right){
        temp.push_back(arr[r]);
        r++;
    }

    for(int i=left; i<=right; i++){
        arr[i] = temp[i-left];
    }    
}

void merge_sort(vector <int>& arr, int left, int right){
    if(left>=right) return;
    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merged(arr, left, mid, right);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int left = 0;
    int right = n-1;

    merge_sort(arr, left, right);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
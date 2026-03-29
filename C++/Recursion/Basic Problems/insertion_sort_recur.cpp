#include<bits/stdc++.h>
using namespace std;

void recursiveInsertionSort(vector<int>& arr, int n){
    if(n<=1) return;

    recursiveInsertionSort(arr, n-1);

    int last = arr[n-1];
    int j = n-2;

    while(j>=0 && arr[j]>last){
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = last;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    recursiveInsertionSort(arr, n);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void recursiveBubbleSort(vector<int>& arr, int n){
    if(n==1) return;

    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }

    recursiveBubbleSort(arr, n-1);
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    recursiveBubbleSort(arr, n);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}
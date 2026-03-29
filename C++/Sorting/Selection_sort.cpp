#include<bits/stdc++.h>
using namespace std;

// select minimum index and sorting 
// O(n2) for best, worst, avg

void selection_sort(int n, int arr[]){
    for(int i=0; i<=n-2; i++){
        int min = i;
        for(int j=i; j<=n-1; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    selection_sort(n, arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
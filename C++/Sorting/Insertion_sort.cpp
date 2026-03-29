#include<bits/stdc++.h>
using namespace std;

// taking an element from an array and inserting at its right position
// O(n) for best and O(N2) for worst

void insertion_sort(int n, int arr[]){
    for(int i=0; i<=n-1; i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    insertion_sort(n, arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
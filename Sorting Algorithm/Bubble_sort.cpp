#include<bits/stdc++.h>
using namespace std;

// swapping two adjacent numbers if they are not in a correct order and repeat until the whole array is sorted
// O(n) for best and O(N2) for worst

void bubble_sort(int n, int arr[]){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
    bubble_sort(n, arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
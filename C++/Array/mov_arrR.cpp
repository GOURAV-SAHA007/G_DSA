#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    int d;
    cin >> d;

    //MOV ARR BY 1 PLACE
    // int temp = arr[n-1];
    // for(int i=n-2; i>=0; i--){
    //     arr[i+1] = arr[i];
    // }
    // arr[0] = temp;

    //D times, METHOD 1
    // while(d--){
    //     int temp = arr[n-1];
    //     for(int i=n-2; i>=0; i--) arr[i+1] = arr[i];
    //     arr[0] = temp;
    // }

    //D times, METHOD 2
    // int tempArr[d];
    // for(int i=0; i<n-d; i++) tempArr[i] = arr[i];
    // for(int i=0; i<d; i++) arr[i] = arr[n-d+i];
    // for(int i=d; i<n; i++) arr[i] = tempArr[i-d];
    
    //OPTIMAL APPROACH
    reverse(arr, arr+n);
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
}
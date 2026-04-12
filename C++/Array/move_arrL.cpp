#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    int d;
    cin >> d;
    int drr[d];

    //MOV BY 1 PLACE
    // int temp = arr[0];
    // for(int i=1; i<n; i++){
    //     arr[i-1] = arr[i];
    // }
    // arr[n-1] = temp;

    //MOV BY X PLACES METHOD 1
    // int d;
    // cin >> d;
    // while(d--){
    //    int temp = arr[0];
    //    for(int i=1; i<n; i++){
    //        arr[i-1] = arr[i];
    //    }
    //    arr[n-1] = temp;
    // }

    //MOV BY X PLACES METHOD 2
    // for(int i=0; i<d; i++) drr[i] = arr[i];
    // for(int i=d; i<n; i++){
    //     arr[i-d] = arr[i];
    // }
    // for(int i=0; i<d; i++) arr[n-d+i] = drr[i];

    //OPTIMAL CASE
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);

    for(int k=0; k<n; k++) cout << arr[k] << " ";

    return 0;

}
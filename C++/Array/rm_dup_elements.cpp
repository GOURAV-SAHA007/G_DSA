#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    //BRUTE FORCE
    // set<int> st;
    // for(int i=0; i<n; i++){
    //     st.insert(arr[i]);
    // }

    // int index = 0;
    // for(auto it: st){
    //     arr[index++] = it;
    // }

    // for(int i=0; i<index; i++) cout << arr[i] << " ";

    //OPTIMAL SOLUTION
    int i=0;
    for(int j=1; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    for(int k=0; k<=i; k++) cout << arr[k] << " ";
    return 0;
}
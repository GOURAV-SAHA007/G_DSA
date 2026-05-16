#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int num;
    cout << "Enter the number to find: ";
    cin >> num;

    for(int i=0; i<n; i++){
        if(arr[i]==num){
            cout << "Number found at index: " << i << endl;
            return 0;
        }
    }
    cout << "Number not found" << endl;
    return 0;
}
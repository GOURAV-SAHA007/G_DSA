#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int hash[12] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    int index = max_element(hash, hash+n) - hash;
    cout << "Maximum Occuring Element is :" << index;

    int q;
    cin >> q;
    while(q--){
        int num;
        cin >> num;
        cout << hash[num] << endl;
    }

    return 0;
}
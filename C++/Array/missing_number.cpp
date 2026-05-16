#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int size = n+1;
    vector<int> hash(size, 0);

    for(int i=0; i<size; i++){
        hash[arr[i]]++;
    }

    for(int i=1; i<size; i++){
        if(hash[i]==0){
            cout << i << " ";
        }
    }

    return 0;

}
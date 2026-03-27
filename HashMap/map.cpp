#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mpp;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        mpp[arr[i]]++; 
    }

    for(auto it:mpp){
        cout << it.first << ":" << it.second << endl;
    }

    int maxIndex = 0;
    for(int i=1; i<n; i++){
        if(mpp[i] > mpp[maxIndex]){
            maxIndex = i;
        }
    }

    cout << "Maximum Occuring Element is:" << maxIndex;

    int q;
    cin >> q;
    while (q--){
        int num;
        cin >> num;
        cout << mpp[num] << endl;
    }

    return 0;
}
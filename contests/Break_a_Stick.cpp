#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> L(n);
    int total = 0;

    for(int i = 0; i < n; i++){
        cin >> L[i];
        total += L[i];
    }

    int minDiff = INT_MAX;
    int leftSum = 0;

    for(int i = 0; i < n-1; i++){  
        leftSum += L[i];
        int rightSum = total - leftSum;
        int diff = abs(leftSum - rightSum);
        minDiff = min(minDiff, diff);
    }

    cout << minDiff << "\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int, int> p = {1,3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> q = {9, {34, 87}};
    cout << q.second.first << endl;

    pair<int, int>arr[] = {{23,32}, {8,9}, {78,67}};
    cout << arr[2].first;
    return 0;
}
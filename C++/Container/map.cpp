#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, int>mpp;

    mpp.insert({1,3});
    mpp[2]=9;
    mpp.insert({3,7});
    mpp[4]=5;

    for(auto it:mpp){
        cout << it.first << " " << it.second << endl;
    }

    auto it1 = mpp.find(2);
    cout << *(it1).second << endl;
}
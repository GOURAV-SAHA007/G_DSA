#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int>ms;

    ms.insert(9);
    ms.insert(7);
    ms.insert(4);
    ms.insert(4);
    ms.insert(4);
    ms.insert(1);

    int count = ms.count(4);
    cout << count << endl;

    ms.erase(9);

    cout << *ms.begin() << endl;

}
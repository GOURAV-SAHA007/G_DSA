#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int>s;

    s.insert(8);
    s.insert(5);
    s.insert(1);
    s.insert(10);

    s.erase(5);

    cout << *s.begin();
    
    return 0;
}
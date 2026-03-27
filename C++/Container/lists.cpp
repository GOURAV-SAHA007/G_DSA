#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(3);
    ls.emplace_front(1);

    for(auto it=ls.begin(); it!=ls.end(); it++){
        cout << *(it);
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;

    dq.push_back(8);
    dq.emplace_back(76);
    dq.emplace_back(77);
    dq.emplace_front(0);

    for(auto it=dq.begin(); it!=dq.end(); it++){
        cout << *(it) << " ";
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(9);
    pq.push(5);
    pq.emplace(87);
    pq.push(6);

    cout << pq.top() << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int>q;

    q.push(1);
    q.push(8);
    q.emplace(7);

    cout << q.back() << endl;
    q.back() += 3;
    cout << q.back() << endl;

    cout << q.front() << endl;

    q.pop();
    cout << q.front() << endl;
}
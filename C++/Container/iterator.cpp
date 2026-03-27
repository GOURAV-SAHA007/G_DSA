#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v;

    v.push_back(6);
    v.emplace_back(3);
    v.emplace_back(8);
    v.emplace_back(5);
    v.emplace_back(7);
    v.emplace_back(4);
    v.emplace_back(1);

    vector<int>::iterator it = v.begin();

    it++;
    cout << *(it) << " " << endl;

    it = it + 2;
    cout << *(it) << " " << endl;

    // for(vector<int>::iterator it = v.begin(); it!=v.end(); it++){
    //     cout << *(it) << " ";
    // }

    for(auto it = v.begin(); it!=v.end(); it++){
        cout << *(it) << " ";
    }
    cout << endl;

    v.erase(v.begin()+1, v.begin()+5);


    for(auto it = v.begin(); it!=v.end(); it++){
        cout << *(it) << " ";
    }

    vector<int> v1(5, 99);

    v.insert(v.begin(), 300);

    for(auto it = v.begin(); it!=v.end(); it++){
         cout << *(it) << " ";
    }

    cout << v1.empty();
}
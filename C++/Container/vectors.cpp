#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v;

    v.push_back(6);
    v.emplace_back(3);
    v.emplace_back(8);
    v.emplace_back(5);

    cout << v[2] << endl;

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

    vector<pair<int, int>> v1;
    v1.push_back({34,7});
    v1.emplace_back(8,9);

    vector<int> v2(5, 69);
    vector<int> v3(6);
    vector<int> v4(v2);
}
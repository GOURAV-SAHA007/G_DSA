#include<bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;

    vector<long long> trees;
    int result[Q];

    for(int i = 0; i < Q; i++){
        int q;
        long long h;
        cin >> q >> h;

        if(q == 1){
            trees.push_back(h);
        }else{
            trees.erase(remove_if(trees.begin(), trees.end(), [h](long long x) {return x <= h;}), trees.end());
        }

        result[i] = trees.size();
    }

    for(int i=0; i<Q; i++){
        cout << result[i] << endl;
    }

    return 0;
}
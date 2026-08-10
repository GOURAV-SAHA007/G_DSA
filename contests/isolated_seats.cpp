#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int chair_cnt = 0;

    for(int i=0; i<n; i++){
        if(s[i]=='o') continue;
        bool left = (i==0) || (s[i-1]=='x');
        bool right = (i==n-1) || (s[i+1]=='x');
        chair_cnt += (left&&right);
    }
    cout<<chair_cnt<<endl;

}
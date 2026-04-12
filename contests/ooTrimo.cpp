#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    char ch = 'o';
    int i=0;
    while(i<s.size() && s[i]==ch) i++;
    s.erase(0,i);
    cout << s << endl;

    return 0;
}
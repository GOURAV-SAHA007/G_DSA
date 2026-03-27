#include<bits/stdc++.h>
using namespace std;

bool check_palindrome(string s, int i){
    if(i >= s.size()/2) return true;

    if(s[i] != s[s.size()-i-1]) return false;
    return check_palindrome(s, i+1);
}
int main(){
    string s = "madamji";
    cout << check_palindrome(s, 0);
    return 0;
}
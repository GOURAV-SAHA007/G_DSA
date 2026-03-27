#include<bits/stdc++.h>
using namespace std;

bool checkPal(string s, int i){
    if(i==s.size()/2){
        return true;
    }
    if(s[i]!=s[s.size()-i-1]){
        return false;
    }
   return checkPal(s, i+1);
}

int main(){
    string s = "malyaylam";
    cout << checkPal(s, 0);
 
}
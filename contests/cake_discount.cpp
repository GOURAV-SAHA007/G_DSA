#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int total;
    
    if(n<5){
        total = n*100;
    }else{
        total = (n*100) - n*(100 * 15/100);
    }
    cout << total;
}

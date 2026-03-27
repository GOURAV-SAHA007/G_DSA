#include<bits/stdc++.h>
using namespace std;

//2 Methods

int main(){
    int n;
    cout << "Enter the number:";
    cin >> n;

    // int count=0;
    // while(n>0){
    //     n = n/10;
    //     count++;
    // }

    int count = (int)(log10(n)+1);

    cout << "Number of digits:" << count;
    return 0;
}
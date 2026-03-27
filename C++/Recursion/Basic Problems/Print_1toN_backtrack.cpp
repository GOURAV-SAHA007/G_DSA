#include<bits/stdc++.h>
using namespace std;

void printN(int n){
    if(n<1){
        return;
    }
    printN(n-1);
    cout << n << " ";
}

void printNInv(int n, int i){
    if(i>n){
        return;
    }
    printNInv(n, i+1);
    cout << i << " ";
}

int main(){
    printNInv(10,1);
}
#include<bits/stdc++.h>
using namespace std;

void printNtimes(int i, int n){
    if(i>n){
        return;
    }
    cout << i << " ";
    printNtimes(i+1, n);
}

void printNInv(int i, int n){
    if(n<0){
        return;
    }
    cout << n << " ";
    printNInv(i, n-1);
}

int main(){
    printNInv(1,22);

}
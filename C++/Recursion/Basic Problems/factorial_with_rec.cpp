#include<bits/stdc++.h>
using namespace std;

// parameterized
// void factor(int n, int fact){
//     if(n<1){
//         cout << fact;
//         return;
//     }

//     factor(n-1, fact*n);
// }

//functional
int factor(int n){
    if(n==1){
        return 1;
    }

    return n * factor(n-1);
}

int main(){
    cout << factor(6);
}
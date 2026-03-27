#include<bits/stdc++.h>
using namespace std;

//Parameterized
// void sumOfN(int i, int sum){
//     if(i<1){
//         cout << sum;
//         return;
//     }

//     sumOfN(i-1, sum+i);
// }

//function
int sumOfN(int n){
    if(n==0){
        return 0;
    }

    return n + sumOfN(n-1);

}

int main(){
    cout << sumOfN(10);
}
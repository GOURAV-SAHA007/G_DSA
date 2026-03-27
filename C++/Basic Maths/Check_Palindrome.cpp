#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dup = n;
    int revNum = 0;
    while(n>0){
        int lD = n%10;
        revNum = (revNum*10)+lD;
        n/=10;
    }

    if(revNum==dup){
        cout << "True";
    }else{
        cout << "False";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number:";
    cin >> n;

    int rev_num = 0;
    while(n>0){
        int last_digit = n%10;
        rev_num = (rev_num*10)+last_digit;
        n/=10;
    }
    cout << rev_num;
}
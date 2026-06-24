#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;

    int chefina_seat = x + 1;

    int chef_row = (x-1)/5;
    int chefina_row = (chefina_seat-1)/5;

    if(chef_row == chefina_row){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
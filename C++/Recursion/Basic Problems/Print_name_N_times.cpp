#include<bits/stdc++.h>
using namespace std;

void print_Name(int i, int n){
    if(i>n){
        return;
    }

    cout << "Gourav" << endl;
    print_Name(i+1, n);
}

int main(){
    print_Name(1,3);
}

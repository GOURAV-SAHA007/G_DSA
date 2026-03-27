#include<bits/stdc++.h>
using namespace std;

void printName(string name){
    cout << "hey!" << name;
}

void sum(int a, int b){
    int c = a+b;
    cout << c;
}

int main(){
    string name;
    name = "Agni";
    // printName(name);
    int a, b;
    cin >> a >> b;
    sum(a,b);
    return 0;
}
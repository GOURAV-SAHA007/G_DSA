#include<bits/stdc++.h>
using namespace std;

int main(){
    int grade;
    cin >> grade;
    if(grade>=90){
        cout << "Ex";
    }else if(grade>=80 && grade <90){
        cout <<"A";
    }else if(grade>= 70 && grade <80){
        cout <<"B";
    }else if(grade >= 60 && grade <70){
        cout <<"C";
    }else if(grade >= 40 && grade < 60){
        cout<<"D";
    }else{
        cout<<"Gerrr out a here!!";
    }
    return 0;
}
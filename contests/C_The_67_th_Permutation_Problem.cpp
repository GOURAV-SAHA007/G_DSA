#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int n;
        cin >> n;
        int start =1;
        int mid = 3*n-1;
        int end = 3*n;
        for(int j=0;j<n;j++){
            cout<<start<<" ";
            cout<<mid<<" ";
            cout<<end<<" ";
            start+=1;
            mid-=2;
            end-=2;
        }
        cout<<endl;
    }
}
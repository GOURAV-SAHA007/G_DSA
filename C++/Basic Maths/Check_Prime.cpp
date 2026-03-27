#include<bits/stdc++.h>
using namespace std;

//2 Method

int main(){
    int n;
    cin >> n;
    int count = 0;

    //Brute Force O(N)
    // for(int i=1; i<=n; i++){
    //     if(n%i==0){
    //         count++;
    //     }
    // }

    //O(sqrt(N))
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            count++;
            if((n/i)!=i){
                count++;
            }
        }
    }

    if(count==2){
        cout << "Prime";
    }else{
        cout << "Not Prime";
    }
}
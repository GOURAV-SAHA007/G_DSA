#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int max_count = 0;
    int curr_count =0;
    for(int i=0; i<n; i++){
        if(a[i]==1){
            curr_count++;
        }else{
            max_count=max(max_count, curr_count);
            curr_count=0;
        }
    }
    max_count=max(max_count, curr_count);
    cout << max_count << endl;
    return 0;
}
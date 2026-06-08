#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
    
        int target_sum = a[0]+a[n-1];

        bool is_magic_mirror = true;
        for(int i=0; i<n/2; i++){
            int curr_sum = a[i]+a[n-1-i];
            if(curr_sum!=target_sum){
                is_magic_mirror = false;
                break;
            }
        }
        cout << (is_magic_mirror ? "YES" : "NO") << endl;
    }
    return 0;
}
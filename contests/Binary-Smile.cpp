#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        for(int i=0; i<n; i++){
            if(a[i]==b[i]){
                cout << 0 << endl;
                break;
            }
        }

        int count_a = 0;
        int count_b = 0;
        for(int i=0; i<n; i++){
            if(a[i] == 1) count_a++;
            if(b[i] == 1) count_b++;
        }

        if(count_a != count_b){
            cout << -1 << endl;
        } 

        int l = -1;
        int r = -1;
        for(int i=0; i<n; i++){
            if(a[i]!=b[i]){
                if(l == -1){
                    l = i;
                }
                r = i;
            }
        }

        int windows_ones_a = 0;
        int windows_ones_b = 0;
        for(int i=l; i<=r; i++){
            if(a[i] == 1) windows_ones_a++;
            if(b[i] == 1) windows_ones_b++;
        }

        if(windows_ones_a <= 1 && windows_ones_b <= 1) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
    return 0;
}
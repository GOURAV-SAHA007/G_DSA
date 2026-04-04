#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
     int n;
        cin >> n;

        int val = 1;
        for(int i = 2; i <= 18; i++) val *= i;

        int gen = 0;

        int n17=2, n13=2, n11=2, n7=3, n5=4, n3=9, n2=17;

        for(int a = 0; a < n17; a++) {
            for(int i13 = 0; i13 < n13; i13++) {
                int p13 = 1;
                for(int k = 0; k < i13; k++) p13 *= 13;

                for(int i11 = 0; i11 < n11; i11++) {
                    
                    int p11 = 1;
                    for(int k = 0; k < i11; k++) p11 *= 11;

                    for(int i7 = 0; i7 < n7; i7++) {
                        int p7 = 1;
                        for(int k = 0; k < i7; k++) p7 *= 7;

                        for(int i5 = 0; i5 < n5; i5++) {
                            int p5 = 1;
                            for(int k = 0; k < i5; k++) p5 *= 5;

                            for(int i3 = 0; i3 < n3; i3++) {
                                int p3 = 1;
                                for(int k = 0; k < i3; k++) p3 *= 3;

                                int p2 = 1;
                                for(int i2 = 0; i2 < n2; i2++) {

                                    int x = val / (p13 * p11 * p7 * p5 * p3 * p2);

                                    cout << x << " ";
                                    gen++;

                                    if(gen == n) return ;

                                    p2 *= 2;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << endl;
}

int32_t main(){
    int T;
    cin >> T;
    while(T--){
        
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        long long n, c, k;cin>>n>>c>>k;
        vector<int> v(n);for(int &i:v) cin>>i;
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++){
            if(v[i]<=c){
                long long temp=min(k+v[i], c);
                c+=temp;
                k-=(temp-v[i]);
                if(k<0) k=0;
            }
        }
        cout<<c<<endl;
    }
}
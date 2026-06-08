#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i=0;
    int j=0;
    int sushi = 0;

    while(i<n && j<m){
        int curr_shari = a[i];
        int curr_neta = b[j];

        if(curr_neta <= 2*curr_shari){
            i++;
            j++;
            sushi++;
        }else{
            i++;
        }
    }
    cout << sushi << endl;
    return 0;
} 
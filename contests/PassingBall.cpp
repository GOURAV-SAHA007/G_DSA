#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<bool> received(n, false);
        int curr = 0;
        received[curr] = true;

        for(int i=0; i<s.size(); i++){
            if(s[curr] == 'R'){
                curr++;
            }else{
                curr--;
            }
            received[curr] = true;
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(received[curr]){
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int w[n];
        int count0=0;
        int count1=0;
        int count2=0;
        int operations=0;

        for(int i=0; i<n; i++){
            cin >> w[i];
            if(w[i]==0){
                count0++;
            }else if(w[i]==1){
                count1++;
            }else{
                count2++;
            }
        }

        operations = operations+count0;

        int pairs = min(count1, count2);
        operations = operations+pairs;
        count1 = count1 - pairs;
        count2 = count2 - pairs;

        operations = operations + (count1 / 3);
        operations = operations + (count2 / 3);
        cout << operations << endl;
    }
    return 0;
}

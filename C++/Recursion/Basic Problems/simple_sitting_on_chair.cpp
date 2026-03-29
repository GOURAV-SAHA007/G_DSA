#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n;
        cin >> n;
        vector<int> p(n+1);
        for(int i=1; i<=n; i++) cin >> p[i];

        int max_chairs = 0;

        for(int mask=0; mask<(1<<n); mask++){
            vector<bool> marked(n+1, false);
            int count = 0;
            bool valid = true;

            for(int j=1; j<=n; j++){
                if(marked[j]){
                    valid = false;
                    break;
                }

                if((mask >> (j-1)) & 1){
                    marked[p[j]] = true;
                    count++;
                }
            }

            if(valid){
                max_chairs = max(max_chairs, count);
            }
        }
        
        cout << max_chairs << endl;
    }
    
    return 0;
}
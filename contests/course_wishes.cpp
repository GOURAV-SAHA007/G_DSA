#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(k+2);
        for(int i=1; i<=k; i++) cin >> a[i];
        a[k+1] = n; 
        vector<int> b(n);
        vector<int> course_count(k+2, 0);
        for(int i=0; i<n; i++){
            cin >> b[i];
            course_count[b[i]]++;
        }

        bool impossible = false;
        for(int i = 1; i < k; i++){
            if(a[i] > a[i+1]){
                impossible = true;
                break;
            }
        }

        if(impossible){
            cout << -1 << "\n";
            continue;
        }

        vector<int> ops;
        bool moved = true;
        while(moved && ops.size() <= 1000){
            moved = false;
            for(int level = k; level >= 1; level--){
                for(int i = 0; i < n; i++){
                    if(b[i] == level && course_count[level+1] < a[level+1]){
                        course_count[level]--;
                        b[i]++;
                        course_count[level+1]++;
                        ops.push_back(i+1);
                        moved = true;
                    }
                }
            }
        }

        bool allDone = true;
        for(int i = 0; i < n; i++) if(b[i] != k+1) { allDone = false; break; }

        if(!allDone) cout << -1 << "\n";
        else {
            cout << ops.size() << "\n";
            for(int i = 0; i < (int)ops.size(); i++)
                cout << ops[i] << " \n"[i+1==(int)ops.size()];
        }
    }
}
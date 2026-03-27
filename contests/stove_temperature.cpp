#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    string result[T];
    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        vector<int> B(n);
        for(int i=0; i<n; i++){
            cin >> B[i];
        }

        int max_temp = max_element(B.begin(), B.end()) - B.begin();

        bool possible = true;
        for(int i=0; i<n; i++){
            if(B[i] < B[max_temp]){
                int count = 0;
                for(int j=0; j<n; j++){
                    if(B[j] == B[i]){
                        count++;
                    }
                }
                if(count>1) possible = false;
            }
        }

        if(possible){
            result[t] = "Yes";
        }else{
            result[t] = "No";
        }
        
    }

    for(int t=0; t<T; t++){
        cout << result[t] << endl;
    }
    
    return 0;
}
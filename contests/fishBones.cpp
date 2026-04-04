#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }

    int M;
    cin >> M;
    vector<string> S(M);
    for(int i=0; i<M; i++){
        cin >> S[i];
    }

    bool valid[11][11][26] = {};
    for(int i=0; i<M; i++){
        string s = S[i];
        int L = (int)s.size();
        for(int p=0; p<L; p++){
            char c = s[p];
            int letter = c - 'a';
            valid[L][p+1][letter] = true;
        }
    }

    for(int j=0; j<M; j++){
        string spine = S[j];
        int spineLen = (int)spine.size();
        if(spineLen != N){
            cout << "No" << endl;
            continue;
        }

        bool ok = true;
        for(int i=0; i<N; i++){
            int len = A[i];
            int pos = B[i];
            char c = spine[i];
            int letter = c-'a';
            if(!valid[len][pos][letter]){
                ok = false;
                break;
            }
        }

        if(ok){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
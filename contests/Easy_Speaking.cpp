#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;   
        string s;
        cin >> s; 

        bool hard_to_pronounce = false;
        int consonant_count = 0;

        for(int i = 0; i < n; i++) {
            char c = s[i];
            
            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
                consonant_count++;
            } else {
                consonant_count = 0; 
            }

            if(consonant_count >= 4){
                hard_to_pronounce = true;
                break;
            }
        }

        cout << (hard_to_pronounce ? "YES" : "NO") << "\n";
    }
    return 0;
}
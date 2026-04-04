#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    string results[n];
    for(int i=0; i<n; i++){
        string word;
        cin >> word;

        if(word.length()>=10){
            int len = word.length()-2;
            results[i] = word[0] + to_string(len) + word[word.length()-1];
        }else{
            results[i] = word;
        }
    }

    for(int i=0; i<n; i++){
        cout << results[i] << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1(n1), arr2(n2);
    for(int i=0; i<n1; i++) cin >> arr1[i];
    for(int i=0; i<n2; i++) cin >> arr2[i];

    //Brute Force
    // set<int> st;
    // for(int i=0; i<n1; i++){
    //     st.insert(arr1[i]);
    // }
    // for(int i=0; i<n2; i++){
    //     st.insert(arr2[i]);
    // }

    // vector<int> unionArr;
    // for(auto it: st){
    //     unionArr.push_back(it);
    // }

    // for(int i=0; i<unionArr.size(); i++){
    //     cout << unionArr[i] << " ";
    // }

    // Optimal Approach
    int i = 0, j =0;
    vector<int> unionArr;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            if(unionArr.empty() || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else {
            if(unionArr.empty() || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n1){
        if(unionArr.empty() || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
    }

    while(j<n2){
         if(unionArr.empty() || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
    }

    for(int i=0; i<unionArr.size(); i++){
        cout << unionArr[i] << " ";
    }

    return 0;
}
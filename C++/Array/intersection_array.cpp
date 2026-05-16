#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    for(int i = 0; i < n1; i++) cin >> arr1[i];
    for(int i = 0; i < n2; i++) cin >> arr2[i];

    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);

        //Brute Force
    // int vis[n2] = {0};
    // vector<int> intersection;

    // for(int i=0; i<n1; i++){
    //     for(int j=0; j<n2; j++){
    //         if(arr1[i] == arr2[j] && vis[j] == 0){
    //             intersection.push_back(arr1[i]);
    //             vis[j] = 1;
    //             break;
    //         }
    //     }
    // }

    // for(auto x:intersection) cout << x << " ";

    //Optimal Approach
    vector<int> intersection;
    int i=0, j=0;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            i++;
        }else if(arr1[i] > arr2[j]){
            j++;
        }else{
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    for(auto x:intersection) cout << x << " ";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool isPossible(long long target, int n, long long k, vector<long long>& a){
    long long total = 0;
    for(int i=1; i<=n; i++){
        long long curr_hight = a[i-1];
        if(curr_hight<target){
            long long diff = target - curr_hight;
            long long points = (diff+i-1)/i;

            if(points > k) return false;
            total += points;
        }
    }
    return total <= k;
}

int main(){
    int n;
    long long k;
    cin >> n >> k;
    
    vector<long long> a(n);
    long long low = 1e18;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < low) low = a[i];
    }

    long long high = 2e18;
    long long answer = low;

    while(low <= high){
        long long mid = (low + high) / 2;
        
        if(isPossible(mid, n, k, a)){
            answer = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}
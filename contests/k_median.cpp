#include <bits/stdc++.h>
using namespace std;

vector<int> findValidElements(const vector<int>& a, int n, int k) {
    int m = n - k;
    int pos = ceil(m / 2.0) - 1;

    map<int,int> freq;
    for (int num : a) freq[num]++;

    vector<int> keys, counts;
    for (auto& p : freq) {
        keys.push_back(p.first);
        counts.push_back(p.second);
    }

    int sz = keys.size();
    vector<long long> prefix(sz+1,0);
    for (int i=0;i<sz;i++) prefix[i+1] = prefix[i] + counts[i];

    vector<int> result;
    for (int i=0;i<sz;i++) {
        int x = keys[i];
        int e = counts[i];
        long long l = prefix[i];
        long long g = prefix[sz] - prefix[i+1];
        if (l >= pos && e >= 1 && (g + (e - 1)) >= (m - pos - 1)) {
            result.push_back(x);
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());

        vector<int> valid = findValidElements(a,n,k);
        for (int i=0;i<(int)valid.size();i++) {
            if (i>0) cout << " ";
            cout << valid[i];
        }
        cout << "\n";
    }
}

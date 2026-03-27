#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    vector<int> answers;
    answers.reserve(T);

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        sort(A.begin(), A.end(), greater<int>());

        int profit = 0;
        for (int i = 0; i < N; ++i) {
            int cost = (i < K) ? 5 : 10;
            int p = A[i] - cost;
            if (p > 0) profit += p;
        }

        answers.push_back(profit);
    }

    for (int v : answers) cout << v << '\n';
    return 0;

}
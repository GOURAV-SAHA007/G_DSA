#include<bits/stdc++.h>
using namespace std;

int N;
long long L[25];

int solve(int index, double pos) {
    if (index == N) {
        return 0;
    }

    double next_pos_pos = pos + L[index];
    int cross_pos = 0;
    if ((pos > 0 && next_pos_pos < 0) || (pos < 0 && next_pos_pos > 0)) {
        cross_pos = 1;
    }
    int res1 = cross_pos + solve(index + 1, next_pos_pos);

    double next_pos_neg = pos - L[index];
    int cross_neg = 0;
    if ((pos > 0 && next_pos_neg < 0) || (pos < 0 && next_pos_neg > 0)) {
        cross_neg = 1;
    }
    int res2 = cross_neg + solve(index + 1, next_pos_neg);

    return max(res1, res2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    cout << solve(0, 0.5) << endl;

    return 0;
}
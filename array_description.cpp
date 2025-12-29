#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<long long> prev_dp(m + 1, 0);

    // Base Case: First element
    if (arr[0] == 0) {
        for (int i = 1; i <= m; i++) prev_dp[i] = 1;
    } else {
        prev_dp[arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        vector<long long> temp_dp(m + 1, 0);
        if (arr[i] != 0) {
            int j = arr[i];
            temp_dp[j] = prev_dp[j];
            if (j - 1 >= 1) temp_dp[j] = (temp_dp[j] + prev_dp[j - 1]) % MOD;
            if (j + 1 <= m) temp_dp[j] = (temp_dp[j] + prev_dp[j + 1]) % MOD;
        } else {
            for (int j = 1; j <= m; j++) {
                temp_dp[j] = prev_dp[j];
                if (j - 1 >= 1) temp_dp[j] = (temp_dp[j] + prev_dp[j - 1]) % MOD;
                if (j + 1 <= m) temp_dp[j] = (temp_dp[j] + prev_dp[j + 1]) % MOD;
            }
        }
        prev_dp = move(temp_dp); 
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + prev_dp[i]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
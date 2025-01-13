#include <bits/stdc++.h>

using namespace std;

int solve(int x, vector<int> &arr, vector<int> &dp) {
    if (x < 0) {
        return INT_MAX; // No solution for negative x.
    }

    if (x == 0) {
        return 0; // Base case: no coins needed to make 0.
    }

    if (dp[x] != -1) {
        return dp[x]; // Return precomputed result.
    }

    int ways = 0;

    for (size_t i = 0; i < arr.size(); i++) { 
        ways = min(ways, solve(x - arr[i], arr, dp));
        ways += 1;
    }

    dp[x] = ways;
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(x + 1, -1);

    int ans = solve(x, arr, dp);

    if (ans == INT_MAX) {
        return -1;

    }

    return ans;

}

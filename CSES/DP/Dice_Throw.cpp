#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int ind, int n, vector<int> &coins, vector<int> &dp) {
    if (n < 0) {
        return 0;  // Invalid, return an impossible value
    }

    if (n == 0) {
        return 1;  
    }

    if (dp[n] != -1) {
        return dp[n]; 
    }

    int res = 0;
    for (int i = ind; i < coins.size(); i++) {
        res = (res + solve(i, n - coins[i], coins, dp)) % mod;
    }

    return dp[n] = res;
}

int main() {
    int n, x;

    cin >> n >> x;  

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];  
    }

    vector<int> dp(x + 1, -1);  

    int result = solve(0, x, c, dp);
    if (result == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << result << endl;  
    }

    return 0;
}

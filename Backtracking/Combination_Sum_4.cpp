class Solution {
public:
    int solve(int &ans, vector<int> &a, int &t, int sum, int ind, int n, vector<int> &dp) {
        if (sum == t) {
            return 1; 
        }
        if (sum > t) {
            return 0; 
        }

        if (dp[sum] != -1) {
            return dp[sum];
        }

        int ways = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum <= t) {
                ways += solve(ans, a, t, sum, i, n, dp);
            }
            sum -= a[i]; 
        }

        return dp[sum] = ways;
    }

    int combinationSum4(vector<int>& a, int t) {
        int ans = 0;

        vector<int> dp(t + 1, -1);

        ans = solve(ans, a, t, 0, 0, a.size(), dp);

        return ans;
    }
};

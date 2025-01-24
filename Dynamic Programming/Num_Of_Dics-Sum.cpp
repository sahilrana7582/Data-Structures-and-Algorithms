class Solution
{
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int n, int k, int t)
    {
        if (n == 0 && t == 0)
        {
            return 1;
        }
        if (n == 0 || t <= 0)
        {
            return 0;
        }

        if (dp[n][t] != -1)
        {
            return dp[n][t];
        }

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = (ans + solve(n - 1, k, t - i)) % MOD;
        }

        return dp[n][t] = ans;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target);
    }
};

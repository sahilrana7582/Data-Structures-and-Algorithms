class Solution
{
public:
    int dp[5001][1001];
    const int MOD = 1e9 + 7;
    int f(int st, int en, int k)
    {
        if (k == 0)
        {
            return st == en ? 1 : 0;
        }
        if (dp[st + 1000][k] != -1)
        {
            return dp[st + 1000][k];
        }
        int left = f(st + 1, en, k - 1);
        int right = f(st - 1, en, k - 1);

        return dp[st + 1000][k] = (left + right) % MOD;
    }
    int numberOfWays(int startPos, int endPos, int k)
    {

        memset(dp, -1, sizeof(dp));

        return f(startPos, endPos, k);
    }
};
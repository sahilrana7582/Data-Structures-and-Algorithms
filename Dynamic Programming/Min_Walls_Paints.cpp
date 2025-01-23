class Solution
{
public:
    int solve(vector<int> &cost, vector<int> &time, int ind, int walls, vector<vector<int>> &dp)
    {

        if (walls <= 0)
        {
            return 0;
        }

        if (ind < 0)
        {
            return 1e9;
        }

        if (dp[ind][walls] != -1)
        {
            return dp[ind][walls];
        }

        int left = cost[ind] + solve(cost, time, ind - 1, walls - time[ind] - 1, dp);
        int right = 0 + solve(cost, time, ind - 1, walls, dp);

        return dp[ind][walls] = min(left, right);
    }
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(cost, time, n - 1, n, dp);
    }
};
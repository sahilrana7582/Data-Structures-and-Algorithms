class Solution {
public:
    int dfs(int row, int col, int n, int m, vector<vector<int>>& a, int dr[],
            int dc[], int& ans, int last, int sum, vector<vector<int>>& dp) {

        if (row >= n|| row < 0 || col >= m || col < 0 || a[row][col] <= last) {
            return 0;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }



        int res = 0;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            res = max(res, 1 + dfs(newRow, newCol, n, m, a, dr, dc, ans,
                               a[row][col], sum + 1, dp));
        }

        return dp[row][col] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& a) {

        int n = a.size();
        int m = a[0].size();
        int ans = INT_MIN;

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, n, m, a, dr, dc, ans,  -1, 0, dp));
            }
        }

        return ans;
    }
};
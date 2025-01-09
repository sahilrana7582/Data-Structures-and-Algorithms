class Solution {
public:
    const int mod = 1e9 + 7;
    
    int solve(int row, int col, int n, int m, vector<vector<int>> &a, vector<vector<vector<int>>> &dp, int sum, int k) {
        if (row == n - 1 && col == m - 1) {
            sum += a[row][col];

            if (sum % k == 0) {
                return 1;
            }
            return 0; 
        }

        if (dp[row][col][sum] != -1) {
            return dp[row][col][sum];
        }
        
        int down = 0, right = 0;


        if (row + 1 < n) {
            down = solve(row + 1, col, n, m, a, dp, (sum + a[row][col])%k, k);
        }

        if (col + 1 < m) {
            right = solve(row, col + 1, n, m, a, dp, (sum + a[row][col])%k, k);
        }

        int temp = (down + right) % mod;

        return dp[row][col][sum] = temp;
    }

    int numberOfPaths(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return solve(0, 0, n, m, a, dp, 0, k);
    }
};

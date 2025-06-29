class Solution {
    public:
        int MOD = 1e9 + 7;
    
        int solve(int row, int col, int maxMoves, int i, int j,
                  vector<vector<vector<int>>> &dp) {
            if (i < 0 || j < 0 || i >= row || j >= col) {
                return 1;
            }
    
            if (maxMoves == 0) {
                return 0;
            }
    
            if (dp[i][j][maxMoves] != -1) {
                return dp[i][j][maxMoves];
            }
    
            int res = 0;
    
            res = (res + solve(row, col, maxMoves - 1, i - 1, j, dp)) % MOD;
            res = (res + solve(row, col, maxMoves - 1, i + 1, j, dp)) % MOD;
            res = (res + solve(row, col, maxMoves - 1, i, j - 1, dp)) % MOD;
            res = (res + solve(row, col, maxMoves - 1, i, j + 1, dp)) % MOD;
    
            return dp[i][j][maxMoves] = res;
        }
    
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
            vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
            return solve(m, n, maxMove, startRow, startColumn, dp);
        }
    };
    
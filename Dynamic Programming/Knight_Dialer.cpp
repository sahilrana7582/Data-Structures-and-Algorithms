class Solution {
    public:
        int MOD = 1e9 + 7;
        int solve(int i, int j, int n, vector<vector<int>>& mat,
                  vector<pair<int, int>>& moves, vector<vector<vector<int>>>& dp) {
            if (i < 0 || j < 0 || i >= 4 || j >= 3 || mat[i][j] == -1) {
                return 0;
            }
    
            if (n == 1) {
                return 1;
            }
    
            if (dp[i][j][n] != -1)
                return dp[i][j][n];
    
            long long res = 0;
            for (auto [dx, dy] : moves) {
    
                int ni = i + dx, nj = j + dy;
    
                res = (res + solve(ni, nj, n - 1, mat, moves, dp)) % MOD;
            }
    
            return dp[i][j][n] = res;
        }
        int knightDialer(int n) {
    
            vector<vector<int>> mat(4, vector<int>(3, 0));
            int num = 1;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == 3 && (j == 0 || j == 2))
                        mat[i][j] = -1;
                    else
                        mat[i][j] = num++;
                }
            }
    
            vector<vector<vector<int>>> dp(
                4, vector<vector<int>>(3, vector<int>(5001, -1)));
    
            long long ans = 0;
            vector<pair<int, int>> moves = {{2, 1},  {2, -1}, {-2, 1},  {-2, -1},
                                            {-1, 2}, {1, 2},  {-1, -2}, {1, -2}};
    
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    ans = (ans + solve(i, j, n, mat, moves, dp)) % MOD;
                }
            }
    
            return ans;
        }
    };
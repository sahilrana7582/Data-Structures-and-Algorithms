class Solution {
public:
    const int mod = 1e9 + 7;
    int dfs(int row, int col, int n, int m, vector<vector<int>>& a, int last,
            vector<vector<int>> &dp, int dr[], int dc[]) {
                if(row < 0 || row >= n || col < 0 || col >= m || a[row][col] <= last){
                    return 0;
                }

                if(dp[row][col] != -1){
                    return dp[row][col];
                }

                int res = 1;
                for(int i=0; i<4; i++){
                    int nRow = row + dr[i];
                    int nCol = col + dc[i];

                    res =  (res + dfs(nRow, nCol, n, m, a, a[row][col], dp, dr, dc)) % mod;

                }

                dp[row][col] = res;

                return dp[row][col];
            }
    int countPaths(vector<vector<int>>& a) {

        int n = a.size();
        int m = a[0].size();

        long long ans = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = (ans + dfs(i, j, n, m, a, 0, dp, dr, dc))%mod;
            }
        }

        return ans;
    }
};
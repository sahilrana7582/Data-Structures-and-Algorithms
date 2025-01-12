class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<char>>& a,
             int dr[], int dc[], vector<vector<bool>>& vis) {

        vis[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && a[newRow][newCol] == 'X') {
                dfs(newRow, newCol, n, m, a, dr, dc, vis);
            }
        }
    }
    int countBattleships(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();

        int ans = 0;

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'X' && vis[i][j] == false) {
                    dfs(i, j, n, m, a, dr, dc, vis);
                    ans += 1;
                }
            }
        }

        return ans;
    }
};
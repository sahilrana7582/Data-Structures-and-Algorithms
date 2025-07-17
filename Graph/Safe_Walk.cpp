class Solution {
    public:
        bool findSafeWalk(vector<vector<int>>& grid, int health) {
            int n = grid.size();
            int m = grid[0].size();
    
            vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(health + 1, -1)));
    
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
    
            using T = tuple<int, int, int>;
            queue<T> q;
    
            int start_health = health - grid[0][0];
            if (start_health < 0) return false;
    
            q.push({0, 0, start_health});
            vis[0][0][start_health] = 1;
    
            while (!q.empty()) {
                auto [row, col, health_left] = q.front();
                q.pop();
    
                if (row == n - 1 && col == m - 1) {
                    return true;
                }
    
                for (int i = 0; i < 4; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                        int new_h = health_left - grid[newRow][newCol];
    
                        if (new_h >= 1 && vis[newRow][newCol][new_h] == -1) {
                            vis[newRow][newCol][new_h] = 1;
                            q.push({newRow, newCol, new_h});
                        }
                    }
                }
            }
    
            return false;
        }
    };
    
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int ans = INT_MAX;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {e[0], e[1]}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int n = maze.size();
        int m = maze[0].size();
        int enRow = e[0];
        int enCol = e[1];

        maze[enRow][enCol] = '+';

        while (!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int steps = q.front().first;
            q.pop();

            if ((row == 0 || row == n - 1 || col == 0 || col == m - 1) &&
                !(row == enRow && col == enCol)) {
                return steps; 
            }

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    maze[newRow][newCol] != '+') {
                    maze[newRow][newCol] = '+';
                    q.push({steps + 1, {newRow, newCol}});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
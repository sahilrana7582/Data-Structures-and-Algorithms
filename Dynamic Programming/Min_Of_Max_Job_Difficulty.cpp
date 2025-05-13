class Solution {
    public:
        int solve(vector<int>& job, int d, int ind, int n, int& ans,
                  vector<vector<int>>& dp) {
    
            if (ind >= n && d == 0) {
                return 0;
            }
    
            if (ind >= n || d == 0) {
                return INT_MAX;
            }
    
            if (dp[ind][d] != -1) {
                return dp[ind][d];
            }
    
            int currMax = INT_MIN;
            int res = INT_MAX;
    
            for (int i = ind; i <= n - d; i++) {
                currMax = max(currMax, job[i]);
                int next = solve(job, d - 1, i + 1, n, ans, dp);
    
                if (next != INT_MAX) {
                    res = min(res, next + currMax);
                }
            }
    
            return dp[ind][d] = res;
        }
        int minDifficulty(vector<int>& job, int d) {
    
            int n = job.size();
    
            if (n < d) {
                return -1;
            }
    
            int ans = INT_MAX;
    
            vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));
    
            return solve(job, d, 0, n, ans, dp);
    
        }
    };
class Solution {
public:
    int solve(int &ans, vector<int> &po, int num, int n, int s, vector<vector<int>> &dp){

        if(num == 0){
            ans = min(ans, s);
            return ans;
        }

        if(dp[n][num] != -1){
            return dp[n][num];
        }

        int res = INT_MAX;
        for(int i=n; i>=0; i--){
            if(num >= po[i]){
                res = min(res, solve(ans, po, num - po[i], i, s + 1, dp));
            }
        }

        dp[n][num] = res;

        return dp[n][num];
    }
    int numSquares(int n) {

        vector<int> po;

        for(int i=1;i*i<=n;i++){
            po.push_back(i*i);
        }

        int size = po.size();

        vector<vector<int>> dp(size + 1, vector<int>(n + 1, -1));

        int ans = INT_MAX;

        return solve(ans, po, n, po.size() - 1, 0, dp);
        
    }
};
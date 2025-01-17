class Solution {
public:

    int solve(int i, int j, string& s, int& n, vector<vector<int>> &dp) {
        if(i > j || i >=n || j < 0){
            return 0;
        }

        if(i == j){
            return s[i] == s[j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        int l = 0, r = 0;
        if(s[i] == s[j]){
            ans += 2 + solve(i + 1, j - 1, s, n, dp);
        }else{
            l += solve(i + 1, j, s, n, dp);
            r += solve(i, j - 1, s, n, dp);
        }

        ans += max(l, r);

        return dp[i][j] = ans;

    }
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));

        return solve(0, n - 1, s, n,  dp);
    }
};
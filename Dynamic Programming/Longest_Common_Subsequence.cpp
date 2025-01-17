class Solution {
public:
    int solve(int i, int j, int &n, int &m, string &a, string &b, vector<vector<int>> &dp){
        if(i >= n || j >= m){
            return 0;
        }


        if(dp[i][j] != -1){
            return dp[i][j];
        }



        int ans1 = 0;
        int left = 0;
        int right = 0;

        if(a[i] == b[j]){
            ans1 += 1 + solve(i + 1, j + 1, n, m, a, b, dp);
        }else{
            left += solve(i + 1, j, n, m, a, b, dp);
            right += solve(i, j + 1, n, m, a, b, dp);
        }

        ans1 += max(left, right);

        return dp[i][j] = ans1;





    }
    int longestCommonSubsequence(string s, string s2) {
        int n = s.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

        return solve(0, 0, n, m, s, s2, dp);
        
    }
};
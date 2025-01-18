class Solution {
public:
    int solve(int i, string &s, int e, vector<vector<int>> &dp){

        if(i >= e){
            return 0 ;
        }

        if(dp[i][e] != -1){
            return dp[i][e];
        }




        int ans = 0;
        int l = 0;
        int r = 0;
        if(s[i] == s[e]){
            ans += solve(i + 1, s, e - 1, dp);
        }else{
            l += 1 + solve(i + 1, s, e, dp);
            r += 1 + solve(i , s, e - 1, dp);
        }

        ans += min(l, r);

        return dp[i][e]=ans;
    }
    int minInsertions(string s) {

        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

        int ans = solve(0, s, n - 1, dp);
        return ans;
        
    }
};
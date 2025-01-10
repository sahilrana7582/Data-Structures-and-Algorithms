class Solution {
public:
    int solve(string &vow, int ind, int len, int n, vector<vector<int>> &dp) {
        if (len == n) {
            return 1; 
        }

        if (dp[ind][len] != -1) {
            return dp[ind][len];
        }

        int ways = 0;
        for (int i = ind; i < vow.size(); i++) { 
            ways += solve(vow, i, len + 1, n, dp);
        }

        return dp[ind][len] = ways; 
    }

    int countVowelStrings(int n) {
        string vowel = "aeiou";
        int m = vowel.size();

        vector<vector<int>> dp(m, vector<int>(n + 1, -1));

        return solve(vowel, 0, 0, n, dp);
    }
};

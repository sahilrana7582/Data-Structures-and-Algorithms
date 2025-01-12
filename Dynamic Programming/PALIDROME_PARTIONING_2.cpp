class Solution {
public:
    bool isPali(int st, int en, string &s) {
        while (st < en) {
            if (s[st] != s[en]) {
                return false;
            }
            st++;
            en--;
        }
        return true;
    }

    void solve(int ind, string &s, int &ans, int sum, vector<int> &dp) {
        if (ind == s.size()) {
            ans = min(ans, sum - 1); 
            return;
        }

        if (dp[ind] != -1) {
            ans = min(ans, dp[ind] + sum - 1);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (isPali(ind, i, s)) {
                solve(i + 1, s, ans, sum + 1, dp);
            }
        }

        dp[ind] = ans - sum + 1; 
    }

    int minCut(string s) {
        int ans = INT_MAX;
        vector<int> dp(s.size(), -1);

        solve(0, s, ans, 0, dp);
        return ans;
    }
};

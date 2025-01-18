class Solution {
public:
    bool solve(int ind, string &s, unordered_map<string, int> &mpp, vector<int> &dp) {
        if (ind == s.size()) {
            return true;
        }

        if (dp[ind] != -1) {
            return dp[ind];
        }

        for (int i = ind; i < s.size(); i++) {
            string temp = s.substr(ind, i - ind + 1); 
            if (mpp[temp]) {
                if (solve(i + 1, s, mpp, dp)) {
                    return dp[ind] = true;
                }
            }
        }

        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mpp;
        for (const string &word : wordDict) {
            mpp[word] = 1;
        }

        vector<int> dp(s.size(), -1);  
        return solve(0, s, mpp, dp);
    }
};

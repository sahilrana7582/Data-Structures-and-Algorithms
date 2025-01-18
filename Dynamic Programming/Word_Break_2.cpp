class Solution {
public:
    void solve(int ind, int n, string &s, unordered_map<string, int> &mpp, vector<string> &ans, string t) {
        if (ind >= n) {
            t.pop_back();
            ans.push_back(t);
            return;
        }

        for (int i = ind; i < n; i++) {
            string temp = s.substr(ind, i - ind + 1);
            if (mpp[temp]) {
                solve(i + 1, n, s, mpp, ans, t + temp + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_map<string, int> mpp;
        for (string word : wordDict) {
            mpp[word] = 1; 
        }

        vector<string> ans;
        solve(0, n, s, mpp, ans, "");

        return ans;
    }
};

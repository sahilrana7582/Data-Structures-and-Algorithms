class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        int n = a.size();
        unordered_map<int, int> dp; 
        int ans = 0;

        for (int i = 0; i < n; i++) {
            dp[a[i]] = 1 + dp[a[i] - d];
            ans = max(ans, dp[a[i]]);
        }

        return ans;
    }
};

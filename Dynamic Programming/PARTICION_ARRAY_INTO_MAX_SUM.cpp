class Solution {
public:
    int solve(int ind, vector<int> &a, int &k, int &n, vector<int> &dp) {
        if (ind >= n) {
            return 0; 
        }

        if (dp[ind] != -1) {
            return dp[ind];  
        }

        int maxSum = INT_MIN;

        for (int i = 0; i < k && ind + i < n; i++) {
            int maxVal = INT_MIN;
            
            for (int j = ind; j <= ind + i; j++) {
                maxVal = max(maxVal, a[j]);
            }

            int sum = maxVal * (i + 1);

            maxSum = max(maxSum, solve(ind + i + 1, a, k, n, dp) + sum);
        }

        return dp[ind] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);  
        return solve(0, arr, k, n, dp);  
    }
};

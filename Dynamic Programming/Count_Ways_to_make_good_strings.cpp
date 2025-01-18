class Solution {
public:
    int solve(int low, int high, int zero, int one, int length, vector<int> &dp) {
        if (length > high) {
            return 0;
        }

        if (dp[length] != -1) {
            return dp[length];
        }

        int count = 0;
        if (length >= low && length <= high) {
            count = 1;
        }

        count = (count + solve(low, high, zero, one, length + zero, dp)) % 1000000007;
        count = (count + solve(low, high, zero, one, length + one, dp)) % 1000000007;

        return dp[length] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(low, high, zero, one, 0, dp);
    }
};

class Solution {
public:
    bool solve(int ind, int n, vector<int>& a, vector<int>& memo) {
        if (ind == n) {
            return true; 
        }
        if (ind > n) {
            return false; 
        }
        if (memo[ind] != -1) {
            return memo[ind]; 
        }

        bool ans = false;

        if (ind + 1 < n && a[ind] == a[ind + 1]) {
            ans = solve(ind + 2, n, a, memo);
        }

        if (!ans && ind + 2 < n && a[ind] == a[ind + 1] && a[ind + 1] == a[ind + 2]) {
            ans = solve(ind + 3, n, a, memo);
        }

        if (!ans && ind + 2 < n && a[ind + 1] - a[ind] == 1 && a[ind + 2] - a[ind + 1] == 1) {
            ans = solve(ind + 3, n, a, memo);
        }

        return memo[ind] = ans; 
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1); 
        return solve(0, n, nums, memo);
    }
};

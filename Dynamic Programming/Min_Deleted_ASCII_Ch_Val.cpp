class Solution {
public:
    int solve(int ind, int ind2, int n, int m, string& a, string& b,
              vector<vector<int>>& memo) {
        if (ind >= n && ind2 >= m) {
            return 0;
        }
        if (ind >= n || ind2 >= m) {
            int sum = 0;
            if (ind < n) {
                for (int i = ind; i < n; i++) {
                    sum += a[i];
                }
            }
            if (ind2 < m) {
                for (int i = ind2; i < m; i++) {
                    sum += b[i];
                }
            }
            return sum;
        }

        if (memo[ind][ind2] != -1) {
            return memo[ind][ind2];
        }

        int ans = 0;
        int l = 0, r = 0;
        if (a[ind] == b[ind2]) {
            ans += solve(ind + 1, ind2 + 1, n, m, a, b, memo);
        } else {
             l += a[ind] + solve(ind + 1, ind2, n, m, a, b, memo);
             r += b[ind2] + solve(ind, ind2 + 1, n, m, a, b, memo);
            ans = min(l, r);
        }

        return memo[ind][ind2] = ans;
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return solve(0, 0, n, m, s1, s2, memo);
    }
};
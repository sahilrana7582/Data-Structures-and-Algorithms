class Solution {
public:
    int dp[501][501];
    int solve(int ind, int ind2, int n, int m, string &a, string &b){
        if(ind == n && ind2 == m){
            return 0;
        }

        if (ind >= n || ind2 >= m) {
            return (n - ind) + (m - ind2);
        }


        if(dp[ind][ind2] != -1){
            return dp[ind][ind2];
        }


        int ans = 0;
        if(a[ind] == b[ind2]){
            ans = solve(ind + 1, ind2 + 1, n, m, a, b);
        }else{
            int in = 1 + solve(ind, ind2 + 1, n, m, a, b);
            int re = 1 + solve(ind + 1, ind2 + 1, n, m, a, b);
            int de = 1 + solve(ind + 1, ind2, n, m, a, b);

            ans = min(in, min(re, de));
        }

        return dp[ind][ind2] = ans;
    }
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, n, m, a, b);
    }
};
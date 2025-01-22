class Solution {
public:
    unordered_map<int, int> m;
    int dp[2000][2000];

    bool solve(int ind, int k, vector<int> &a){
        if(ind >= a.size() - 1){
            return true;
        }

        if(dp[ind][k] != -1){
            return dp[ind][k];
        }


        bool ans = false;

        if(!ans && m.find(a[ind] + k) != m.end()){
            ans = solve(m[a[ind] + k], k, a);
        }

        if(!ans && k > 1 && m.find(a[ind] + (k - 1)) != m.end()){
            ans = solve(m[a[ind] + (k - 1)], k - 1, a);
        }

        if(!ans && m.find(a[ind] + (k + 1)) != m.end()){
            ans = solve(m[a[ind] + (k + 1)], k + 1, a);
        }

        dp[ind][k] = ans;


        return dp[ind][k];
    }
    bool canCross(vector<int>& stones) {
        if (stones[1] - stones[0] != 1) {
            return false;
        }

        for (int i = 0; i < stones.size(); i++) {
            m[stones[i]] = i;
        }

        memset(dp, -1, sizeof(dp));

        return solve(1, 1, stones);
    }
};
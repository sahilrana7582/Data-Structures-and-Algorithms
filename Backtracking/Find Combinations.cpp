class Solution {
public:
    void solve(vector<int>& temp, vector<vector<int>>& ans, int& k, int ind,
               int n) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i <= n; i++) {
            temp.push_back(i);
            solve(temp, ans, k, i + 1, n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(temp, ans, k, 1, n);

        return ans;
    }
};
class Solution {
public:
    void solve(vector<int>& a, int n, int ind, int& ans) {

        if (ind == a.size()) {
            ans += 1;
            return;
        }

        for (int i = ind; i < a.size(); i++) {
            swap(a[ind], a[i]);

            if((ind + 1) % a[ind] == 0 || a[ind] % (ind + 1) == 0){
                solve(a, n, ind + 1, ans);
            }

            swap(a[i], a[ind]);
        }
    }
    int countArrangement(int n) {

        int ans = 0;
        vector<int> d;

        for (int i = 0; i < n; i++) {
            d.push_back(i + 1);
        }

        solve(d, n, 0, ans);

        return ans;
    }
};
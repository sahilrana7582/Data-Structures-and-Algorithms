class Solution {
public:
    void solve(string &s, vector<bool> &mpp, string temp, int &n, unordered_set<string> &ans) {
        for (int i = 0; i < n; i++) {
            if (mpp[i]) continue;

            mpp[i] = true;
            temp.push_back(s[i]);
            ans.insert(temp);  
            solve(s, mpp, temp, n, ans);
            mpp[i] = false;
            temp.pop_back();           
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> mpp(n, false);
        unordered_set<string> ans;

        solve(tiles, mpp, "", n, ans);
        return ans.size();
    }
};

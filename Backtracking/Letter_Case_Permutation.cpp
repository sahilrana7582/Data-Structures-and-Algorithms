class Solution {
public:
    void solve(int ind, int n, vector<string>& ans, string &temp, string& s) {

        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < n; i++) {
            if (isdigit(s[i])) {
                temp.push_back(s[i]);
                solve(i + 1, n, ans, temp , s);
                temp.pop_back();

            } else {
                char ch = tolower(s[i]);
                temp.push_back(ch);
                solve(i + 1, n, ans, temp, s);
                temp.pop_back();
                char newCh = toupper(ch);
                if (ch != newCh) {
                    temp.push_back(newCh);

                    solve(i + 1, n, ans, temp , s);
                    temp.pop_back();
                }
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n = s.size();

        vector<string> ans;

        string temp;

        solve(0, n, ans, temp, s);

        return ans;
    }
};
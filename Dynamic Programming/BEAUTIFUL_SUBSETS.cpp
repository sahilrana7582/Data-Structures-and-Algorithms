class Solution {
public:
    void solve(int ind, vector<int>& a, int k, int& ans, vector<int> &temp) {
        if (ind >= a.size()) {
            if (temp.size() > 1) { 
                bool valid = true;
                for (int i = 0; i < temp.size() - 1 && valid == true ; i++) {
                    for (int j = i + 1; j < temp.size(); j++) {
                        if (abs(temp[i] - temp[j]) == k) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (valid) {
                    ans++;
                }
            } else {
                ans++; 
            }
            return;
        }

        temp.push_back(a[ind]);
        solve(ind + 1, a, k, ans, temp);
        temp.pop_back();

        solve(ind + 1, a, k, ans, temp);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> temp;
        solve(0, nums, k, ans, temp);
        return ans - 1;
    }
};

class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &a, vector<int> &temp,
               int t, int ind, int sum)
    {

        if (sum == t)
        {
            ans.push_back(temp);
        }

        if (ind >= a.size())
        {
            return;
        }
        int last = INT_MIN;
        for (int i = ind; i < a.size(); i++)
        {
            if (last != a[i])
            {
                last = a[i];
                sum += a[i];
                if (sum <= t)
                {
                    temp.push_back(a[i]);
                    solve(ans, a, temp, t, i + 1, sum);
                    temp.pop_back();
                }
                sum -= a[i];
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &c, int t)
    {

        vector<vector<int>> ans;

        sort(c.begin(), c.end());

        vector<int> temp;

        solve(ans, c, temp, t, 0, 0);

        return ans;
    }
};
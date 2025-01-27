class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> mpp;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            vector<int> ans;
            for (int j = 0; j < m; j++)
            {
                ans.push_back(grid[i][j]);
            }
            mpp[ans] += 1;
        }

        int ans1 = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> ans;
            for (int j = 0; j < m; j++)
            {
                ans.push_back(grid[j][i]); // Construct the column vector
            }
            if (mpp.find(ans) != mpp.end())
            {
                ans1 += mpp[ans]; // Add the frequency of the matching row to
                                  // the count
            }
        }

        return ans1;
    }
};
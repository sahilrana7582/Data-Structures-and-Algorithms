class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> mpp;

        for (int in : arr)
        {
            mpp[in] += 1;
        }
        unordered_set<int> st;
        for (auto &pair : mpp)
        {
            if (st.find(pair.second) != st.end())
            {
                return false;
            }
            st.insert(pair.second);
        }

        return true;
    }
};
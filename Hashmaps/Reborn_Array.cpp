class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& a) {
        unordered_map<int, vector<int>> mpp;
        int start;

        for(auto &pair : a){
            mpp[pair[0]].push_back(pair[1]);
            mpp[pair[1]].push_back(pair[0]);
        }

        for(auto &pair : mpp){
            if(pair.second.size() == 1){
                start = pair.first;
                break;
            }
        }


        vector<int> ans;
        unordered_set<int> st;
        ans.push_back(start);
        st.insert(start);
        int last = start;


        while(ans.size() < a.size() + 1){
            for(auto nei : mpp[last]){
                if(!st.count(nei)){
                    ans.push_back(nei);
                    st.insert(nei);
                    last = nei;
                }
            }
        }


        return ans;
    }
};
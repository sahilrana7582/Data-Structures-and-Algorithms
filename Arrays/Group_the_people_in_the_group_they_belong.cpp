class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int, vector<int>> mpp;

        for(int i=0;i<g.size(); i++){
            mpp[g[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for(auto &pair : mpp){
            int size = pair.first;
            vector<int> arr = pair.second;
            int i = 0;
            while(i < arr.size()){
                vector<int> temp;

                for(int j = i; j<size + i; j++){
                    temp.push_back(arr[j]);
                }
                ans.push_back(temp);
                i = size + i;
            }
        }

        return ans;
    }
};
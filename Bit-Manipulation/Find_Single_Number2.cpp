/*------ Using MAP  ------*/
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            unordered_map<int, int> mpp;
    
            for(int in : nums){
                mpp[in]++;
            }
    
            for(auto &pair : mpp){
                if(pair.second == 1){
                    return pair.first;
                }
            }
    
    
            return -1;
        }
    }
};


/*---- Using Bit Manipulation -----*/
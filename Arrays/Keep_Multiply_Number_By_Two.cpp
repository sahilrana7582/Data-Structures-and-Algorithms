class Solution {
    public:
        bool find(int x, vector<int> &a){
            for(auto i : a){
                if(i == x){
                    return true;
                }
            }
    
            return false;
        }
        int findFinalValue(vector<int>& nums, int o) {
    
            while(find(o, nums)){
                o = 2 * o;
            }
    
            return o;
        }
    };
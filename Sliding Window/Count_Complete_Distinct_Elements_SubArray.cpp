class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_set<int> st;
    
            for(int a : nums){
                st.insert(a);
            }
    
            int dist = st.size();
            int ans = 0;
            int left = 0;
            int right = 0;
            int n = nums.size();
            unordered_map<int, int> mpp;
            while(right < n){
                mpp[nums[right]]++;
    
                while(mpp.size() == dist){
    
                    ans += (n - right);
    
                    mpp[nums[left]]--;
    
                    if(mpp[nums[left]] == 0){
                        mpp.erase(nums[left]);
                    }
    
                    left++;
                }
    
                right++;
            }
    
            return ans;
    
        }
    };
class Solution {
    public:
        int ans = 0;
    
        bool allUnique(string &temp){
            set<char> st;
    
            for(char ch:temp){
                if(st.find(ch) != st.end()){
                    return false;
                }else{
                    st.insert(ch);
                }
            }
    
            return true;
        }
    
    
        void solve(int ind, int n, vector<string> &arr, string temp){
            if(!allUnique(temp)){
                return;
            }
    
    
            int size = temp.size();
            ans = max(ans, size);
    
            for(int i=ind; i<n; i++){
                solve(i + 1, n, arr, temp + arr[i]);
            }
        }
    
        int maxLength(vector<string>& arr) {
            
            int n = arr.size();
    
            solve(0, n, arr, "");
            
    
    
            return ans;
        }
    };
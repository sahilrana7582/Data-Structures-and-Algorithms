class Solution {
    public:
        string smallestNumber(string pattern) {
            stack<char> st;
            char a = '1';
            string ans;
    
    
            for(char ch : pattern){
                if(ch == 'I'){
                    st.push(a);
                    while(!st.empty()){
                        ans += st.top();
                        st.pop();
                    }
                }else{
                    st.push(a);
                }
    
                a = a + 1;
            }
    
            ans += a;
    
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
    
    
    
            return ans;
    
    };
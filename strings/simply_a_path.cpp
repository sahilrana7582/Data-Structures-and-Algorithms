class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;

        stringstream ss(path);
        string dir;

        while (getline(ss, dir, '/')) {
            if (dir == "..") {
                if (!st.empty()) st.pop(); 
            } else if (!dir.empty() && dir != ".") {
                st.push(dir);  
            }
        }

        string ans;

        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.size() == 0 ? "/" : ans;
        
    }
};
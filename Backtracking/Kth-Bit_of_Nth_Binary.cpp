class Solution {
public:
    string reverseInvert(string temp){
        for(int i=0;i<temp.size(); i++){
            temp[i] = temp[i] == '0' ? '1' : '0';
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
    void solve(int k, string &ans, int n){


        if(k == n){
            return;
        }



        string temp = ans;
        ans += "1";
        ans += reverseInvert(temp);

        solve(k + 1, ans, n);


    }
    char findKthBit(int n, int k) {

        string ans = "0";

        solve(1, ans, n);



        return ans[k - 1];
        
    }
};

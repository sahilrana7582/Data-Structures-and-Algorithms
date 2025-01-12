//First Recursive Solution
class Solution {
public:
    bool isPali(int st, int en, string &s){
        while(st < en){
            if(s[st] != s[en]){
                return false;
            }
            st++;
            en--;
        }

        return true;
    }
    void solve(int ind, string &s, bool &ans, int &n, int sum){

        if(ind >= n){
            ans = ans || false;
            return;
        }

        if(sum == 2){
            ans = ans || isPali(ind, n - 1, s);
            return;
        }

        for(int i=ind;i<n;i++){
            if(isPali(ind, i, s)){
                solve(i + 1, s, ans, n, sum + 1);
            }
        }
    }
    bool checkPartitioning(string s) {

        bool ans = false;

        int n = s.size();

        solve(0, s, ans, n, 0);



        return ans;
        
    }
};
// 2nd Solution




class Solution {
public:
    bool isPali(int st, int en, string& s) {
        while (st < en) {
            if (s[st] != s[en]) {
                return false;
            }

            st++;
            en--;
        }
        return true;
    }
    bool checkPartitioning(string s) {

        int n = s.size();

        for (int i = 0; i < n - 2; i++) {
            if (isPali(0, i, s)) {
                for (int j = i + 1; j < n - 1; j++) {
                    if (isPali(i + 1, j, s)) {
                        if (isPali(j + 1, n - 1, s)) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};
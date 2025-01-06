class Solution {
public:
    void solve(vector<int>& arr, int ind, int& ans) {
        if (ind == arr.size()) {
            ans++;
            return;
        }

        for (int i = ind; i < arr.size(); i++) {

            if ((ind + 1) % arr[i] == 0 || arr[i] % (ind + 1) == 0) {
                swap(arr[i], arr[ind]);

                solve(arr, ind + 1, ans);
                swap(arr[i], arr[ind]);
            }
        }
    }
    int countArrangement(int n) {

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        int ans = 0;

        solve(arr, 0, ans);

        return ans;
    }
};
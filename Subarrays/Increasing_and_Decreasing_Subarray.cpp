class Solution {
public:
    int lon(vector<int>& a) {
        int i = 0, j = 1;
        int n = a.size();
        int ans = 1; // At least one element is a valid subarray

        while (j < n) {
            if (a[j] > a[j - 1]) {
                j++;
            } else {
                i = j;
                j++;
            }

            ans = max(ans, j - i); // Fix: Removed +1
        }

        return ans;
    }

    int sor(vector<int>& a) {
        int i = 0, j = 1;
        int n = a.size();
        int ans = 1;

        while (j < n) {
            if (a[j] < a[j - 1]) {
                j++;
            } else {
                i = j;
                j++;
            }

            ans = max(ans, j - i);
        }

        return ans;
    }

    int longestMonotonicSubarray(vector<int>& nums) {
        return max(lon(nums), sor(nums));
    }
};

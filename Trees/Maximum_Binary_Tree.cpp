class Solution {
public:
    int maxEle(vector<int> &a, int st, int en) {
        int maxEleIdx = st;
        for (int i = st; i <= en; i++) {
            if (a[i] > a[maxEleIdx]) {
                maxEleIdx = i;
            }
        }
        return maxEleIdx;
    }

    TreeNode* solve(vector<int> &a, int st, int en) {
        if (st > en) return NULL; // Base case correction

        int maxEleIdx = maxEle(a, st, en);
        TreeNode* root = new TreeNode(a[maxEleIdx]); // Fix incorrect assignment

        root->left = solve(a, st, maxEleIdx - 1);
        root->right = solve(a, maxEleIdx + 1, en);

        return root; // Missing return statement
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};
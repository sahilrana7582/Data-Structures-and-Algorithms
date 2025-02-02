#include <climits>

class Solution {
public:
    int maxSum = INT_MIN;

    int solve(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        int left = max(0, solve(node->left)); 
        int right = max(0, solve(node->right));

        maxSum = max(maxSum, left + right + node->val);

        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};

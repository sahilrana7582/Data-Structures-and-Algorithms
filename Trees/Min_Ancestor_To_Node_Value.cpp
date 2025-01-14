/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* node, int &ans, int mini, int maxi){
        if(node == NULL){
            return;
        }

        ans = max(ans, max(abs(node->val - mini), abs(node->val - maxi)));

        mini = min(mini, node->val);
        maxi = max(maxi, node->val);
        solve(node->left, ans, mini, maxi);
        solve(node->right, ans, mini, maxi);

    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans, root->val, root->val);

        return ans;
    }
};
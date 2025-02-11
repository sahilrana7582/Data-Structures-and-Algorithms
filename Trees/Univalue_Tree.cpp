/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*> q;

        int last = root->val;

        q.push(root);

        while (!q.empty()) {
            int front = q.front()->val;
            TreeNode* node = q.front();
            q.pop();

            if (front != last) {
                return false;
            }

            last = front;

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }
        return true;
    }
};
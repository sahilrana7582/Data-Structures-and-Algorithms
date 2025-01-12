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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return NULL;
        }

        if (!root->left && !root->right) {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool isOdd = false;

        while (!q.empty()) {
            int size = q.size();

            vector<TreeNode*> nodes;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (isOdd) {
                    nodes.push_back(node);
                }

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            if (isOdd) {
                int n = nodes.size();
                for (int i = 0; i < n / 2; i++) {
                    swap(nodes[i]->val, nodes[n - i - 1]->val);
                }
            }

            isOdd = !isOdd;
        }

        return root;
    }
};
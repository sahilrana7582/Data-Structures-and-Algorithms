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
        void solve2(TreeNode* left, TreeNode* right) {
            if (left->left != NULL) {
                solve2(left->left, right);
            } else {
                left->left = right;
            }
            return;
        }
    
        TreeNode* solve(TreeNode* root, TreeNode* par, int& k) {
            if (root == NULL) {
                return NULL;
            }
    
            if (root->val == k) {
                if (root->left && root->right) {
                    solve2(root->right, root->left);
                    return root->right;
                } else if (root->left == NULL && root->right == NULL) {
                    return NULL;
                } else if (root->left == NULL) {
                    return root->right;
                } else {
                    return root->left;
                }
            }
    
            if (root->val > k) {
                root->left = solve(root->left, root, k);
            } else {
                root->right = solve(root->right, root, k);
            }
    
            return root;
        }
    
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == NULL) {
                return NULL;
            }
    
            return solve(root, NULL, key);
        }
    };
    
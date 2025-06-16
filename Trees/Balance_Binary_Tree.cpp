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
        int height(TreeNode* root) {
            if (!root)
                return 0;
            return 1 + max(height(root->left), height(root->right));
        }
    
        bool isBal(TreeNode* node) {
            if (node == NULL) {
                return true;
            }
    
            int leftH = height(node->left);
            int rightH = height(node->right);
    
            return abs(leftH - rightH) <= 1;
        }
    
        bool isBalTree(TreeNode* root) {
            if (!root)
                return true;
            return isBal(root) && isBalTree(root->left) && isBalTree(root->right);
        }
    
    
        void inorder(TreeNode* node, vector<TreeNode*> &a){
            if(node == NULL){
                return;
            }
    
            inorder(node->left, a);
            a.push_back(node);
            inorder(node->right, a);
        }
    
    
        TreeNode* construct( vector<TreeNode*> &a, int st, int en){
            if(st > en){
                return NULL;
            }
    
            int mid = (st + en) / 2;
    
            TreeNode* root = a[mid];
            root->left = construct(a, st, mid - 1);
            root->right = construct(a, mid + 1, en);
    
            return root;
        }
        TreeNode* balanceBST(TreeNode* root) {
            if (isBalTree(root)) {
                return root;
            }
    
            vector<TreeNode*> a;
    
            inorder(root, a);
    
    
            int n = a.size();
    
            
    
    
            return construct( a, 0, n - 1);
        }
    };
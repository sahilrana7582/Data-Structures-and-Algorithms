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
        string solve(TreeNode* root){
            if(root == NULL){
                return "";
            }
            string ans;
            ans += to_string(root->val);
            string left = solve(root->left);
            string right = solve(root->right);
    
            if(left.size() != 0 && right.size() != 0 || left.size() == 0 && right.size() != 0){
                ans += "(" + left + ")" + "(" + right + ")";
            }else if(left.size() != 0){
                ans += "(" + left + ")";
            }
    
            return ans;
    
     
        }
        string tree2str(TreeNode* root) {
            return solve(root);
        }
    };
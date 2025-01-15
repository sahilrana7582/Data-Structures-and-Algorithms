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
    int solve(TreeNode* node, int &les, int last){
        if(node == NULL){
            return 0;
        }

        if(node->val < last){
            les += 1;
        }

        int maxVal = max(last, node->val);
        int left = solve(node->left, les, maxVal);
        int right = solve(node->right, les, maxVal);


        return left + right + 1;

    }
    int goodNodes(TreeNode* root) {

        int les = 0;

        int tot = solve(root, les, INT_MIN);



        return tot - les;
        
    }
};
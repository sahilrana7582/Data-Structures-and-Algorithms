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
    pair<int, int> solve(TreeNode* node, int &ans, int sum, int nodes){

        if(node == NULL){
            return {0, 0};
        }



        pair<int, int> left = solve(node->left, ans, sum, nodes);
        pair<int, int> right = solve(node->right, ans, sum, nodes);

        int totNodes = left.second + right.second + 1;
        int totSum = left.first + right.first + node->val;

        if(totSum/totNodes == node->val){
            ans += 1;
        }

        return {totSum, totNodes};


    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        solve(root, ans, 0, 0);


        return ans;
    }
};
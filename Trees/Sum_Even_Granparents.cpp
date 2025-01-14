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
    int sumEvenGrandparent(TreeNode* root) {

        queue<pair<TreeNode*, pair<TreeNode*, TreeNode*>>> q;

        q.push({root, {NULL, NULL}});

        int ans = 0;

        while(!q.empty()){
            pair<TreeNode*, pair<TreeNode*, TreeNode*>> pair = q.front();
            q.pop();
            TreeNode* node = pair.first;
            TreeNode* par = pair.second.first;
            TreeNode* gPar = pair.second.second;

            if(gPar != NULL && gPar->val % 2 == 0){
                ans += node->val;
            }

            if(node->left){
                q.push({node->left, {node, par}});
            }
            if(node->right){
                q.push({node->right, {node, par}});
            }


        }



        return ans;
        
    }
};
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            vector<TreeNode*> n;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                n.push_back(node);

                if(node->left){
                    q.push(node->left);
                    sum += node->left->val;
                }


                if(node->right){
                    q.push(node->right);
                    sum += node->right->val;
                }
            }

            for(auto node:n){
                int cSum = sum;

                if(node->left){
                    cSum -= node->left->val;
                } 


                if(node->right){
                    cSum -= node->right->val;
                } 

                if(node->left){
                    node->left->val = cSum;
                }


                if(node->right){
                    node->right->val = cSum;
                }
            }

        }



        return root;
    }
};
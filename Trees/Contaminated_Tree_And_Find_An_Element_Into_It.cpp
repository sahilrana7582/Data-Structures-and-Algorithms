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
class FindElements {
public:
    unordered_map<int, int> mpp;
    void solve(TreeNode* root, int val){
        if(root == NULL){
            return;
        }

        root->val = val;
        mpp[root->val] += 1;

        solve(root->left, 2 * val + 1);
        solve(root->right, 2 * val + 2);

    }


    FindElements(TreeNode* root) {
        solve(root, 0);
    }
    
    bool find(int target) {
        if(mpp.find(target) == mpp.end()){
            return false;
        }

        return true;
    }
};


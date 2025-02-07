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
    string solve(TreeNode* node, unordered_map<string, int>& mpp,
                 vector<TreeNode*>& ans, string tem) {
                    if(!node){
                        return "#";
                    }


                    string left = solve(node->left, mpp, ans, tem);
                    string right = solve(node->right, mpp, ans, tem);

                    string path = to_string(node->val)+ "node" + left + "L" + right + "R";
                    cout<<path<<" node-> "<<node->val<<endl;

                    mpp[path]++;
                    if(mpp[path] == 2){
                        ans.push_back(node);
                    }
        return path;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> mpp;
        solve(root, mpp, ans, "");
        return ans;
    }
};
class Solution {
public:
    void solve(TreeNode* node, set<int> &values) {
        if (node == NULL) return;
        
        values.insert(node->val); 
        solve(node->left, values);
        solve(node->right, values);
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> values;
        solve(root, values);

        if (values.size() < 2) return -1; 

        auto it = values.begin();
        return *(++it); 
    }
};

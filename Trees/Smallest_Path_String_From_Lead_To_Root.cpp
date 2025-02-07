class Solution {
public:
    string minStr(string &p, string &temp) {
        if (p.empty()) return temp;
        if (temp.empty()) return p;
        return min(p, temp);
    }

    void solve(TreeNode* node, string& p, string temp) {
        if (!node) return;  

        temp = char(node->val + 'a') + temp; 

        if (!node->left && !node->right) {
            p = minStr(p, temp); 
            return;
        }

        solve(node->left, p, temp);
        solve(node->right, p, temp);
    }

    string smallestFromLeaf(TreeNode* root) {
        string path;
        solve(root, path, "");
        return path;
    }
};

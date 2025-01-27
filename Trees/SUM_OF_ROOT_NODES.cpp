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
class Solution
{
public:
    void solve(TreeNode *node, string temp, int &ans)
    {
        if (node == NULL)
        {
            return;
        }

        if (node->left == NULL && node->right == NULL)
        {
            temp += to_string(node->val);
            ans += stoi(temp);

            return;
        }
        temp += to_string(node->val);
        solve(node->left, temp, ans);
        solve(node->right, temp, ans);
    }
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        solve(root, "", ans);

        return ans;
    }
};
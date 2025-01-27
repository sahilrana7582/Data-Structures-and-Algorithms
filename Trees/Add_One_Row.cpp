class Solution
{
public:
    void solve(TreeNode *node, int val, int depth, int curr)
    {
        if (!node)
            return;

        if (curr == depth - 1)
        {
            TreeNode *newLeft = new TreeNode(val);
            TreeNode *newRight = new TreeNode(val);

            newLeft->left = node->left;
            newRight->right = node->right;

            node->left = newLeft;
            node->right = newRight;

            return;
        }

        solve(node->left, val, depth, curr + 1);
        solve(node->right, val, depth, curr + 1);
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        solve(root, val, depth, 1);

        return root;
    }
};

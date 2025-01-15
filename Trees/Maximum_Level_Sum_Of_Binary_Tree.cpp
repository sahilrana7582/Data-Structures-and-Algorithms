class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1;  
        int maxSum = INT_MIN;  
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 1;
        
        while (!q.empty()) {
            int size = q.size();  
            int tempSum = 0; 
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                tempSum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            if (tempSum > maxSum) {
                maxSum = tempSum;
                ans = level;  
            }
            
            level++; 
        }
        
        return ans;  
    }
};

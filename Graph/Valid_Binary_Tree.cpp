class Solution {
    public:
        bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                     vector<int>& rightChild) {
            vector<int> parent(n, -1);
    
            for (int i = 0; i < n; i++) {
                int left = leftChild[i];
                int right = rightChild[i];
    
                if (left != -1) {
                    if (parent[left] != -1)
                        return false;
                    parent[left] = i;
                }
                if (right != -1) {
                    if (parent[right] != -1)
                        return false;
                    parent[right] = i;
                }
            }
    
            int rootCount = 0, root = -1;
            for (int i = 0; i < n; i++) {
                if (parent[i] == -1) {
                    rootCount++;
                    root = i;
                }
            }
            if (rootCount != 1)
                return false;
    
            vector<bool> vis(n, false);
            function<void(int)> dfs =
                [&](int node) {
                    if (node == -1 || vis[node]) {
                        return;
                    }
    
                    vis[node] = true;
                    dfs(leftChild[node]);
                    dfs(rightChild[node]);
                };
    
                dfs(root);
    
                for(auto v : vis){
                    if(v == false){
                        return false;
                    }
                }
    
            return true;
        }
    };
    
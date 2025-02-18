#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */


class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> sortedArr;

        for (int i = 0; i < n; i++) {
            sortedArr.push_back({arr[i], i});
        }

        sort(sortedArr.begin(), sortedArr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || sortedArr[i].second == i) continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = sortedArr[j].second;
                cycle_size++;
            }

            if (cycle_size > 1)
                swaps += (cycle_size - 1);
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> temp;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();  // Fix: Incorrect variable `w.pop()` changed to `q.pop()`

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }

                temp.push_back(node->val);
            }

            ans += minSwaps(temp);
        }

        return ans;
    }
};

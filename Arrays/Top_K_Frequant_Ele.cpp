class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap; // Count frequencies
        for (int num : nums) {
            umap[num]++;
        }
        
        // Min heap to store {frequency, number}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto& [num, freq] : umap) {
            minHeap.push({freq, num}); 
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the least frequent element
            }
        }
        
        // Extract the top-k elements
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return ans;
    }
};
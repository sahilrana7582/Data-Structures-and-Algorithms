class Solution {
    public:
        int nthUglyNumber(int n) {
            priority_queue<long long> pq;
            priority_queue<long long, vector<long long>, greater<long long>> uglyNumber;
            vector<int> multiple = {2, 3, 5};
            unordered_set<long long> visited;
    
            uglyNumber.push(1);
            visited.insert(1);
    
            while (pq.size() < n) {
                long long ele = uglyNumber.top();
                uglyNumber.pop();
                pq.push(ele);
    
                for (int i = 0; i < multiple.size(); i++) {
                    long long temp = ele * multiple[i];
                    if (visited.find(temp) == visited.end()) {
                        uglyNumber.push(temp);
                        visited.insert(temp);
                    }
                }
            }
    
            while (pq.size() > n) {
                pq.pop();
            }
    
            return (int)pq.top();
        }
    };
    
class Solution {
    public:
        void solve(int start, vector<int>& e, vector<int>& dist, int sum) {
            if (start == -1 || dist[start] != -1) {
                return;
            }
    
            dist[start] = sum; 
    
            solve(e[start], e, dist, sum + 1);
        }
    
        int closestMeetingNode(vector<int>& edges, int node1, int node2) {
            int n = edges.size();
            vector<int> dist1(n, -1);
            vector<int> dist2(n, -1);
    
            solve(node1, edges, dist1, 0);
            solve(node2, edges, dist2, 0);
    
            int res = -1;
            int minMaxDist = INT_MAX;
    
            for(int i=0; i<n; i++){
                if(dist1[i] != -1 && dist2[i] != -1){
                    int newMax = max(dist1[i], dist2[i]);
    
                    if(newMax < minMaxDist){
                        res = i;
                        minMaxDist = newMax;
                    }
                }
            }
    
            return res;
        }
    };
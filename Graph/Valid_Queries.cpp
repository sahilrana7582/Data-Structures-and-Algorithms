class Solution {
    public:
        bool dfs(string curr, string target, unordered_set<string>& visited,
                 double& result, double val,
                 unordered_map<string, vector<pair<string, double>>>& graph) {
            if (curr == target) {
                result = val;
                return true;
            }
    
            visited.insert(curr);
            for (auto& [neighbor, weight] : graph[curr]) {
                if (!visited.count(neighbor)) {
                    if (dfs(neighbor, target, visited, result, val * weight, graph)) {
                        return true;
                    }
                }
            }
            return false;
        }
    
        vector<double> calcEquation(vector<vector<string>>& equations,
                                    vector<double>& values,
                                    vector<vector<string>>& queries) {
    
            unordered_map<string, vector<pair<string, double>>> graph;
    
            // Build graph
            for (int i = 0; i < equations.size(); ++i) {
                string a = equations[i][0];
                string b = equations[i][1];
                double val = values[i];
                graph[a].push_back({b, val});
                graph[b].push_back({a, 1.0 / val});
            }
    
            // Answer queries
            vector<double> result;
            for (auto& q : queries) {
                string src = q[0], dest = q[1];
                if (!graph.count(src) || !graph.count(dest)) {
                    result.push_back(-1.0);
                    continue;
                }
                unordered_set<string> visited;
                double val = -1.0;
                dfs(src, dest, visited, val, 1.0, graph);
                result.push_back(val);
            }
    
            return result;
        }
    };
    
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();

        vector<bool> vis(n, false);

        queue<int> q;

        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(vis[node]) continue;

            vis[node] = true;

            for(int &key:rooms[node]){
                q.push(key);
            }
        }


        for(bool v:vis){
            if(!v){
                return false;
            }
        }

        return true;
    }
};



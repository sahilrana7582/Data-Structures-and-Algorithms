class Solution {
    public:
        int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
            int n = grid.size();
            int sum = 0;
    
            vector<int> rowMax(n, INT_MIN), colMax(n, INT_MIN);
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    rowMax[i] = max(rowMax[i], grid[i][j]);
                    colMax[j] = max(colMax[j], grid[i][j]);
                }
            }
    
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    int maxRowEle = rowMax[i];
                    int maxColEle = colMax[j];
                    int ele = grid[i][j];
    
                    if(ele == maxRowEle || ele == maxColEle){
                        continue;
                    }
    
                    int temp = min(maxRowEle, maxColEle);
                    sum += abs(ele - temp);
    
                }
            }
    
    
            return sum;
    
        }
    };
    
class Solution {
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& b) {
            unordered_map<int, int> minCol, maxCol;
            unordered_map<int, int> minRow, maxRow; 
    
    
            for (auto& a : b) {
                int x = a[0], y = a[1];
                
    
                if (!minCol.count(x)) minCol[x] = y;
                else minCol[x] = min(minCol[x], y);
    
                if (!maxCol.count(x)) maxCol[x] = y;
                else maxCol[x] = max(maxCol[x], y);
    
                if (!minRow.count(y)) minRow[y] = x;
                else minRow[y] = min(minRow[y], x);
    
                if (!maxRow.count(y)) maxRow[y] = x;
                else maxRow[y] = max(maxRow[y], x);
            }
    
            int count = 0;
            for (auto& a : b) {
                int x = a[0], y = a[1];
    
                bool hasLeftAndRight = minCol[x] < y && maxCol[x] > y;
                bool hasUpAndDown = minRow[y] < x && maxRow[y] > x;
    
                if (hasLeftAndRight && hasUpAndDown) {
                    count++;
                }
            }
    
            return count;
        }
    };
    
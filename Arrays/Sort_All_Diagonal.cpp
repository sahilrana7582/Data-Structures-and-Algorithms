#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, int m, vector<vector<int>> &mat){
        priority_queue<int, vector<int>, greater<int>> pq;
        int tempN = n, tempM = m;
        while(tempN < mat.size() && tempM < mat[0].size()){
            pq.push(mat[tempN][tempM]);
            tempN++;
            tempM++;
        }

        while(!pq.empty()){
            mat[n][m] = pq.top();
            pq.pop();
            n++;
            m++;
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();

        for(int i = rows - 1; i >= 0; i--){
            solve(i, 0, mat);
        }

        for(int j = 1; j < cols; j++){
            solve(0, j, mat);
        }

        return mat;
    }
};
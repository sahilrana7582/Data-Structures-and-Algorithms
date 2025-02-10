class Solution {
public:
    void nonDec(int n, int m, vector<vector<int>>& mat) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int tempN = n, tempM = m;

        while (tempN < mat.size() && tempM < mat.size()) {
            pq.push(mat[tempN][tempM]);
            tempN += 1;
            tempM += 1;
        }

        while (!pq.empty()) {
            mat[n][m] = pq.top();
            pq.pop();
            n += 1;
            m += 1;
        }
    }

    void nonInc(int n, int m, vector<vector<int>>& mat) {
        priority_queue<int> pq;
        int tempN = n, tempM = m;

        while (tempN < mat.size() && tempM < mat.size()) {

            pq.push(mat[tempN][tempM]);
            tempN += 1;
            tempM += 1;
        }

        while (!pq.empty()) {
            mat[n][m] = pq.top();
            pq.pop();
            n += 1;
            m += 1;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        for (int i = 1; i < mat.size(); i++) {
            nonDec(0, i, mat);
        }
        for (int i = 0; i < mat.size(); i++) {
            nonInc(i, 0, mat);
        }
        return mat;
    }
};
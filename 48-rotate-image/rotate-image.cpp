class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int layer = 0; layer < n / 2; layer++) {
            for(int i = layer; i < n - 1 - layer; i++) {

                swap(matrix[layer][i],
                     matrix[n-1-i][layer]);

                swap(matrix[n-1-i][layer],
                     matrix[n-1-layer][n-1-i]);

                swap(matrix[n-1-layer][n-1-i],
                     matrix[i][n-1-layer]);
            }
        }
    }
};
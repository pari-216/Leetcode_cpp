class Solution {
private: 
    void dfs(int i, int j, vector<vector<int>>& image, int color, int prevColor){
        int n= image.size();
        int m= image[0].size();
        image[i][j] = color;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int k=0; k<4; k++){
            int row = i+ delrow[k];
            int col = j+ delcol[k];
            if(row>=0 && row<n && col>=0 && col<m && image[row][col]==prevColor){
                dfs(row, col, image, color, prevColor);
            }
        } 
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m= image[0].size();
        int prevColor = image[sr][sc];
        if(prevColor == color) return image;
        image[sr][sc] = color;
        // sr= starting row, sc= starting column, no need to traverse all
        dfs(sr, sc, image, color, prevColor);
        return image;
    }
};
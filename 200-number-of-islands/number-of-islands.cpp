class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j]= '0';
        int delrow[]= {-1, 0, 1, 0};
        int delcol[]= {0, 1, 0, -1};
        for(int k=0; k<4; k++){
            int row = i+delrow[k];
            int col = j+delcol[k];
            if(row>=0 && row<n && col>=0 && col<m && grid[row][col]== '1'){
                dfs(row, col, grid);
            } 
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};
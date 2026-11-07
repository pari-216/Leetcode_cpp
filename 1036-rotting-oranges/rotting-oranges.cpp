class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        int minute=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int delrow[]= {-1, 0, 1, 0};
        int delcol[]= {0, 1, 0, -1};
        while(!q.empty() && fresh>0){
            int size= q.size();
            for(int i=0; i<size; i++){
                auto [row, col] = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    int nrow= delrow[k]+row;
                    int ncol= delcol[k]+col;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                        grid[nrow][ncol]=2;
                        fresh--;
                        q.push({nrow, ncol});
                    }
                }
            }
            minute++;
        }
        if(fresh>0) return -1;
        return minute;
    }
};
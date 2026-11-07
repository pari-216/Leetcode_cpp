class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int delrow[]= {-1, 0, 1, 0};
        int delcol[]= {0, 1, 0, -1};
        while(!q.empty()){
            auto [row, col]= q.front(); 
            q.pop();
            for(int k=0; k<4; k++){
                int nrow= row+delrow[k];
                int ncol= col+delcol[k];
                if(nrow>=0 && nrow< n && ncol>=0 && ncol<m && dist[nrow][ncol]==-1){
                    dist[nrow][ncol]=dist[row][col]+1;
                    q.push({nrow, ncol});
                }
            }
        }
        return dist;
    }
};
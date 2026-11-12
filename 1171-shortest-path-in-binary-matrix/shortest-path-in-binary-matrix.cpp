class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]){
            return -1;
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int,pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0]= 1;
        pq.push({1,{0,0}});
        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};
        while(!pq.empty()){
            int d = pq.top().first;
            auto [row, col] = pq.top().second; 
            pq.pop();
            if(row==n-1 && col==n-1) return d;
            for(int k=0; k<8; k++){
                int nrow= row + drow[k];
                int ncol= col + dcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0){
                    if(d+1< dist[nrow][ncol]){
                        dist[nrow][ncol]=d+1;
                        pq.push({d+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};
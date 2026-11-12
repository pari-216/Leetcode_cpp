class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m= heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, 
        greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        effort[0][0]=0;
        pq.push({0,{0,0}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!pq.empty()){
            int eff = pq.top().first;
            auto [row,col] = pq.top().second;
            pq.pop();
            if(row==n-1 && col==m-1) return eff;
            for(int k=0; k<4; k++){
                int nrow= row+dr[k];
                int ncol= col+dc[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int diff = abs(heights[nrow][ncol]-heights[row][col]);
                    int newEff  = max(eff, diff);
                    if(newEff < effort[nrow][ncol]){
                        effort[nrow][ncol] = newEff;
                        pq.push({newEff,{nrow, ncol}});
                    } 
                }
            }
        }
        return 0;
    }
};
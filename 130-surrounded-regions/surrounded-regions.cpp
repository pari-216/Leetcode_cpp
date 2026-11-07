class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0||i==n-1||j==0||j==m-1)&& board[i][j]=='O'){
                    q.push({i,j});
                    board[i][j]='#';
                }
            }
        } 
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int nrow = delrow[k] + row;
                int ncol = delcol[k] + col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O'){
                    board[nrow][ncol]= '#';
                    q.push({nrow, ncol});
                }    
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};
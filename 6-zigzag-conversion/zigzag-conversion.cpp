class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
          return s;
        vector<vector<char>> arr(numRows, vector<char>(s.length(), '#'));
        string ans="";
        bool down=true;
        int rows=0, col=0;
        for(int i=0; i<s.length(); i++){
            arr[rows][col]= s[i];
            if(rows == numRows - 1)
                down = false;
            if(rows == 0)
                down = true;
            if(down)
                rows++;
            else {
                rows--;
                col++;
            }    
        }
        for(int i=0; i<numRows; i++){
            for(int j=0; j<s.length(); j++){
                if(arr[i][j]!='#')
                 ans+=arr[i][j];
            }
        }
        return ans;
    }
};
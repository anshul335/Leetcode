class Solution {
public:
    void dfs (vector<vector<int>>&matrix,int n,int row,int col){
        vector<vector<int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
        matrix[row][col] = 1;
        for (int i =0;i<4;i++){
            int nextRow = row + direction[i][0];
            int nextCol = col + direction[i][1];
            if (nextRow>=0 && nextRow < n && nextCol>=0 && nextCol< n && matrix[nextRow][nextCol]==0) dfs(matrix,n,nextRow,nextCol);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> matrix(n*3 , vector<int> (n*3,0));
        for (int i =0;i<n;i++){
            for (int j =0;j<n;j++){
                int row = i*3;
                int col = j*3;
                if ( grid[i][j] == '\\'){
                    matrix[row][col] = 1;
                    matrix[row+1][col+1] = 1;
                    matrix[row+2][col+2] = 1;
                }
                else if ( grid[i][j] == '/'){
                    matrix[row][col+2] = 1;
                    matrix[row+1][col+1] = 1;
                    matrix[row+2][col] = 1;
                }
            }
        }
        int ans = 0;

        for (int i =0;i<n*3;i++){
            for (int j =0;j<n*3;j++){
                if (matrix[i][j] == 0){
                    dfs(matrix,n*3,i,j);
                    ans ++;
                }
            }
        }
        

        return ans;
    }
};
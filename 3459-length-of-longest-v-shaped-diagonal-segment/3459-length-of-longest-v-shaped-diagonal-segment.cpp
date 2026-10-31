class Solution {
public:
    vector<vector<int>> dir = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    int memo[501][501][4][3][2];
    int solve(int i , int j , int d,vector<vector<int>>& grid, int val , bool canTurn){
        int n = grid.size();
        int m = grid[0].size();
        if (i <  0 || j >= m || i>=n || j< 0) return 0;
        if (grid[i][j] != val) return 0;
        if (memo[i][j][d][val][canTurn] != -1) return memo[i][j][d][val][canTurn];
        int nextVal = (val == 2) ? 0 : 2;
        int ans = 1 + solve(i + dir[d][0], j + dir[d][1], d, grid, nextVal, canTurn);
        if (canTurn) {
            int new_d = (d + 1) % 4; 
            ans = max(ans, 1 + solve(i + dir[new_d][0], j + dir[new_d][1], new_d,grid, nextVal, false));
        }
        return memo[i][j][d][val][canTurn] = ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(memo, -1,sizeof(memo));
        int ans = 0;
        for(int i =0;i<n;i++){
            for (int j =0;j<m;j++){
                if (grid[i][j] == 1){
                    ans = max(ans, 1);
                    for (int d = 0;d<=3;d++){
                        ans = max(ans,1 + solve(i + dir[d][0], j + dir[d][1], d, grid, 2, true));
                    }
                }
            }
        }
        return ans;
    }
};
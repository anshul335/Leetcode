class Solution {
public:
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid, int x, int y1,  int y2){
        int n = grid.size();
        int m = grid[0].size();
        if (x == n) return 0;
        if (dp[x][y1][y2] != -1) return dp[x][y1][y2];
        vector<int> dir= {-1, 0, 1};
        int ans = 0;
        if (y1 == y2){
            ans += grid[x][y1];
        }
        else {
            ans = grid[x][y1] + grid[x][y2];
        }
        int next = 0;
        for (int i = 0;i<3;i++){
            for (int j = 0;j<3;j++){
                int ny1 = y1 + dir[i];
                int ny2 = y2 + dir[j];
                if (ny1 >= 0 && ny2 >= 0 && ny1 < m && ny2 < m){
                    next = max(next, solve(grid, x+1, ny1, ny2));
                }
            }
        }
        return dp[x][y1][y2] =  ans+ next;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, m-1);
    }
};
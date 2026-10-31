class Solution {
public:
    int solve (vector<vector<int>>& grid, int i , int j, int direction, vector<vector<vector<int>>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        if (i == n-1 && j == m-1) return 1;
        if(i >= n || j >= m) return 0;
        if (dp[i][j][direction] != -1) return dp[i][j][direction];
        const int MOD = 1e9 + 7;
        int ans = 0;
        if (grid[i][j] == 1){
            if (direction == 1){
                ans = (ans + solve(grid, i,j+1, 0, dp)) %MOD;
            }
            else {
                ans = (ans + solve(grid, i+1, j, 1, dp));
            }
        }
        else{
            ans = (ans + solve(grid, i, j+1, 0, dp)) % MOD;
            ans = (ans + solve(grid, i+1, j, 1, dp)) % MOD;
        }
        

        return dp[i][j][direction] =  ans ;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp (n+1,vector<vector<int>> (m+1, vector<int> (2,-1)));
        return solve (grid, 0, 0, 0, dp) ;

    }
};
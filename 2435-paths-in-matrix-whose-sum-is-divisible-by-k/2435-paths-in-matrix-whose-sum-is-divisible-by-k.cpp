class Solution {
public:
    const int MOD = 1e9 + 7;
    // int recursion(vector<vector<int>> & grid, int k ,int x , int y,int sum ){
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if (x == n-1 && y == m-1){
    //         return( sum + grid[x][y] )% k == 0;
    //     }
    //     int right = 0;
    //     int down = 0;
    //     if ( x < n - 1){
    //         right = recursion (grid, k, x +1 , y , sum + grid[x][y]);
    //     }
    //     if (y < m - 1) {
    //         down = recursion(grid, k, x, y+1, sum + grid[x][y]);
    //     }
    //     return right + down ;
    // }
    
    int memo(vector<vector<int>> & grid, int k ,int x , int y,int sum , vector<vector<vector<int>>>&dp ){
        int n = grid.size();
        int m = grid[0].size();
        sum = (sum + grid[x][y]) %k;
        if (x == n-1 && y == m-1){
            return sum  == 0;
        }
        if (dp[x][y][sum] != -1) return dp[x][y][sum];
        int right = 0;
        int down = 0;
        if ( x < n - 1){
            right = memo (grid, k, x +1 , y , sum,dp);
        }
        if (y < m - 1) {
            down = memo(grid, k, x, y+1,sum ,dp);
        }
        return dp[x][y][sum] = (right + down ) % MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(m +1 , vector<int>(k+1,-1)));
        return memo(grid, k, 0, 0, 0, dp);
    }
};
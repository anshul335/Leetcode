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

    // int memo(vector<vector<int>>& grid, int k, int x, int y, int sum,
    //          vector<vector<vector<int>>>& dp) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     sum = (sum + grid[x][y]) % k;
    //     if (x == n - 1 && y == m - 1) {
    //         return sum == 0;
    //     }
    //     if (dp[x][y][sum] != -1)
    //         return dp[x][y][sum];
    //     int right = 0;
    //     int down = 0;
    //     if (x < n - 1) {
    //         right = memo(grid, k, x + 1, y, sum, dp);
    //     }
    //     if (y < m - 1) {
    //         down = memo(grid, k, x, y + 1, sum, dp);
    //     }
    //     return dp[x][y][sum] = (right + down) % MOD;
    // }


    // int numberOfPaths(vector<vector<int>>& grid, int k) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<vector<int>>> dp(
    //         n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
    //     // return memo(grid, k, 0, 0, 0, dp);
    //     int rem = grid[0][0] %k;
    //     dp[0][0][rem] = 1;
    //     for (int x = 0; x < n; x++) {
    //         for (int y = 0; y < m; y++) {
    //             if (x == 0 && y == 0) continue;
    //             int currVal = grid[x][y] % k;
    //             for (int z = 0 ;z< k ;z++){
    //                 int last = (z - currVal + k) %k;
    //                 if (x > 0){
    //                     dp[x][y][z] = (dp[x][y][z] + dp[x-1][y][last]) %MOD;
    //                 }
    //                 if (y > 0){
    //                     dp[x][y][z] = (dp[x][y][z] + dp[x][y-1][last]) %MOD;
    //                 }
    //             }
    //         }
    //     }
    //     return dp[n-1][m-1][0];
    // }


    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prev (m + 1,vector<int> (k + 1,0));
        int rem = grid[0][0] %k;
        prev[0][rem] = 1;
        for (int y = 1; y < m; y++) {
            int val = grid[0][y] % k;

            for (int z = 0; z < k; z++) {
                int last = (z - val + k) % k;

                prev[y][z] = prev[y - 1][last];
            }
        }
        for (int x = 1; x < n; x++) {
            vector<vector<int>> curr (m + 1,vector<int> (k + 1,0));
            for (int y = 0; y < m; y++) {
                if (x == 0 && y == 0) continue;
                int currVal = grid[x][y] % k;
                for (int z = 0 ;z< k ;z++){
                    int last = (z - currVal + k) %k;
                    if (x > 0){
                        curr[y][z] = (curr[y][z] + prev[y][last]) %MOD;
                    }
                    if (y > 0){
                        curr[y][z] = (curr[y][z] + curr[y-1][last]) %MOD;
                    }
                }
            }
            prev = curr;
        }
        return prev[m-1][0];
    }
};
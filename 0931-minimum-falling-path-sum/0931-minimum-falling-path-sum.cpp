class Solution {
public:
    int solve (vector<vector<int>>& mat, int x, int y
            ,vector<vector<int>>&dp){
        int n = mat.size();
        int m = mat[0].size();
        if (x == n) return 0;
        if (y < 0 || y>=m) return INT_MAX;
        if (dp[x][y] != INT_MAX) return dp[x][y];
        int sum = INT_MAX;
        int dir[3]= {-1,0,1};
        for (int i =0;i<3;i++){
            int next = solve(mat, x + 1, y - dir[i],dp);
            if (next != INT_MAX) {
                sum = min(sum, mat[x][y] + next);
            }
        } 
        return dp[x][y] =  sum ;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        vector<vector<int>> dp (matrix.size(),vector<int> (matrix[0].size(), INT_MAX));
        for (int i =0;i<matrix[0].size();i++){
            ans = min(ans, solve(matrix, 0, i,dp));
        }
        return ans ;
    }
};
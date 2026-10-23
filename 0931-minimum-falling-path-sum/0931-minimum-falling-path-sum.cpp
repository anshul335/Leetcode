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
        vector<int> dp (matrix[0].size(), INT_MAX);
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i =0;i<m;i++){
            dp[i] = matrix[0][i];
        }
        for (int i = 1;i<n;i++){
            vector<int> nextDp (matrix[0].size(), INT_MAX);
            for (int j =0;j<m;j++){
                if (j == 0) nextDp[j] = matrix[i][j] + min(dp[j], dp[j+1]);
                else if (j == m-1) nextDp[j] = matrix[i][j] + min(dp[j-1], dp[j]);
                else {
                     nextDp[j] = matrix[i][j] + min({dp[j-1], dp[j], dp[j+1]});
                }
            }
            dp = nextDp;
        }
        int ans = INT_MAX;
        for (int i =0;i<m;i++){
            ans = min(ans, dp[i]);
        }
        return ans ;
    }
};
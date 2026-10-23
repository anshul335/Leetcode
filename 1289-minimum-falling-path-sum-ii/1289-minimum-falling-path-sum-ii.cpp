class Solution {
public:
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
                int minPrev = INT_MAX;
                for (int k = 0; k < m; k++) {
                    if (k != j) {
                        minPrev = min(minPrev, dp[k]);
                    }
                }
                nextDp[j] = matrix[i][j] + minPrev;
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
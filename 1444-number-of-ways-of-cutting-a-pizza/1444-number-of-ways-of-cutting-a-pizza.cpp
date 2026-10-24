class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(vector<vector<int>> & apples , int i , int j , int k, vector<vector<vector<int>>>&dp){
        if (k == 1) {
            return apples[i][j] >= 1 ? 1 : 0; 
        }
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int n = apples.size();
        int m = apples[0].size();

        int ans = 0;
        for (int h = i+1;h<n;h++){
            int low = apples[h][j];
            int up = apples[i][j] - low;
            if (up >= 1 && low >= k-1) {
                ans = (ans + solve(apples, h, j, k-1,dp)) % MOD;
            }
        }

        for (int v = j+1;v<m;v++){
            int right = apples[i][v];
            int left = apples[i][j] - right ;
            if (left >= 1 && right >= k-1){
                ans = (ans + solve(apples, i, v, k-1,dp)) % MOD;
            }
        }
        return dp[i][j][k] =  ans ;

    }
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        vector<vector<int>> apples(n+1, vector<int> (m+1,0));
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1,vector<int>(k+1,-1)));
        for (int i = n-1;i>=0;i--){
            for (int j = m-1;j>=0;j--){
                apples[i][j] = apples[i][j+1];
                for (int k = i;k<n;k++){
                    if (pizza[k][j]  == 'A')apples[i][j]++;
                }
            }
        }

        return solve(apples, 0,0,k,dp);

    }   
};
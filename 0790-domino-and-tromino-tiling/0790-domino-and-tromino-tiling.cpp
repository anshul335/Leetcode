class Solution {
public:
    // Brute
    int MOD = 1e9+7;
    int solve (int n ,int i ,bool possible){
        if (i>n) return 0;
        if (i==n) return !possible;
        if (possible){
            return (solve(n,i+1,false)+solve(n,i+1,true))%MOD;

        }
        return (solve(n,i+1,false)+solve(n,i+2,false) + 2LL * solve(n,i+2,true))%MOD;

    }
    int numTilings(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        vector<int> dp(n + 1, 0);
        dp[0]=1,dp[1]= 1, dp[2] = 2, dp[3] = 5;
        for (int i = 4; i <= n; i++) 
            dp[i] = (dp[i - 1] * 2 + long(dp[i - 3])) % MOD;
        
        return dp[n];

    }
};
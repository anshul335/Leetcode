class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int K) {
        int n = piles.size();
        vector<int>dp(K + 1, 0);
        for (int ind = 0; ind < n; ind++) {
            vector<int>nextDp(K + 1, 0);
            for (int k = 1; k <= K; k++) {
                int ans = dp[k];
                int sum = 0;
                int sz = piles[ind].size();
                for (int i = 0; i < min(k, sz); i++) {
                    sum += piles[ind][i];
                    ans = max(ans, sum + dp[k - i - 1]);
                }
                nextDp[k] = ans;
            }
            dp = nextDp;
        }
        return dp[K];
    }
};
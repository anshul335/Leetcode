class Solution {
public:
    int dp[100000][2];
    int solve (vector<int>&prices, int fee , int ind , int buy){
        int n = prices.size();
        if (ind >= n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];
        int ans = solve(prices,fee,ind+1,buy);
        if (buy){
            ans = max(ans, -prices[ind] + solve(prices,fee,ind +1 ,0));
        }
        else {
            ans = max(ans , prices[ind] - fee + solve(prices,fee, ind+1 ,1));
        }
        return dp[ind][buy]  =ans ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return solve (prices,fee, 0,1);
    }
};
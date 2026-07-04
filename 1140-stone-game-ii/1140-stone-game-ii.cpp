class Solution {
public:
    int dp [105][300][2];
    int solve (int ind ,vector<int>&arr,int m,int alice){
        int n = arr.size();
        if (ind>=n) return 0;
        if (dp[ind][m][alice]!=-1) return dp[ind][m][alice];
        if (!alice){
            int ans = INT_MAX;
            for (int i = 1;i<=2*m && ind+ i<=n;i++){
        
                ans = min(ans, solve(ind+i,arr, max(i,m),!alice));
            }
            return dp[ind][m][alice] = ans;
        }
        int ans = 0;
        int sum = 0;
        for (int i = 1;i<=2*m && ind+ i<=n;i++){
            sum+= arr[ind+i-1];
        
                ans = max(ans,sum + solve(ind+i,arr, max(i,m),!alice));
        }
        return dp[ind][m][alice] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
       return  solve (0,piles,1,1);
    }
};
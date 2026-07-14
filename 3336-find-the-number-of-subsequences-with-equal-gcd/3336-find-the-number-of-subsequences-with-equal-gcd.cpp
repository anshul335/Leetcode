class Solution {
public:
    int dp[201][201][201];
    const int MOD = 1e9+7;
    int solve (vector<int>&nums, int ind, int first ,int second){
        if (ind == nums.size()){
            if (first != 0 && second != 0) return first == second;
            return 0;
        }
        if (dp[ind][first][second]!=-1) return dp[ind][first][second];
        int skip = solve(nums,ind+1,first,second);
        int take1 = solve(nums,ind+1,__gcd(first,nums[ind]),second);
        int take2 = solve(nums,ind+1,first , __gcd(second,nums[ind]));
        return dp[ind][first][second] = (0LL + skip + take1 + take2) % MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,0);
    }
};
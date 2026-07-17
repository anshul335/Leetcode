class Solution {
public:
    int dp[301][301];
    int solve (vector<int>&nums ,int i,int j){
        if (i>j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for (int k = i;k<=j;k++){
            ans=max(ans,nums [k] * nums[i-1] * nums[j+1] + solve(nums,i,k-1) + solve (nums,k+1,j));
        }
        return dp[i][j] = ans ;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(dp,-1,sizeof(dp));
        return solve (nums , 1, nums.size()-2);
    }
};
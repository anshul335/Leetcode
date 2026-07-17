class Solution {
public:
    int dp[305][305];
    // int solve (vector<int>&nums ,int i,int j){
    //     if (i>j) return 0;
    //     if (dp[i][j] != -1) return dp[i][j];
    //     int ans = INT_MIN;
    //     for (int k = i;k<=j;k++){
    //         ans=max(ans,nums [k] * nums[i-1] * nums[j+1] + solve(nums,i,k-1) + solve (nums,k+1,j));
    //     }
    //     return dp[i][j] = ans ;
    // }
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(dp,0,sizeof(dp));
        // return solve (nums , 1, nums.size()-2);
        for (int i = n;i>=1;i--){
            for (int j = 1;j<=n;j++){
                if (i>j) continue;
                int ans = INT_MIN;
                for (int k = i;k<=j;k++){
                    ans=max(ans,nums [k] * nums[i-1] * nums[j+1] + dp[i][k-1] + dp[k+1][j]);
                }
                 dp[i][j] = ans ;
            }
        }
        return dp[1][nums.size()-2];
    }
};
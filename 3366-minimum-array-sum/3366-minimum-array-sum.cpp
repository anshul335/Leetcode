class Solution {
public:
    int dp[105][105][105];
    int solve(vector<int>&nums, int ind , int k , int op1 , int op2){
        int n = nums.size();
        if (ind >= n) return 0;
        if (dp[ind][op1][op2] != -1) return dp[ind][op1][op2];

        int ans = nums[ind] + solve(nums, ind+1, k, op1 , op2);
        if (op1 >0 ){
            ans = min(ans, ((nums[ind]+1)/2) + solve(nums , ind+1, k , op1-1, op2));
        }
        if (op2 >0 && (nums[ind] >=k)){
            ans = min(ans, (nums[ind] - k) + solve(nums , ind+1, k , op1, op2-1));
        }

        if (op1 >0 && op2 >0){
            int firstDiv = (nums[ind] + 1)/2;
            if (firstDiv >= k){
                ans = min(ans, (firstDiv - k) + solve(nums , ind+1, k , op1-1, op2-1));
            }
        }
         if (op1 >0 && op2 >0 && nums[ind] >=k){
            int firstSub = nums[ind] - k;
            ans = min(ans, (firstSub + 1)/2 + solve(nums , ind+1, k , op1-1, op2-1));
            
        }
        return dp[ind][op1][op2] = ans ;


    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp, -1,sizeof(dp));
        return solve (nums, 0, k, op1, op2);
    }
};
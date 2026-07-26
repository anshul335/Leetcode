class Solution {
public:
    vector<vector<int>>dp;
    int solve (vector<int>&nums, int left , int right, int score){
        if (left >= right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        int ans = 0;
        if (nums[left] + nums[left +1 ] == score) ans = max(ans , 1+ solve(nums, left + 2 , right, score));
        if (nums[right] + nums[right-1 ] == score) ans = max(ans , 1+ solve(nums, left  , right -2, score));
        if (nums[left] + nums[right] == score) ans = max(ans , 1+ solve(nums, left + 1 , right-1, score));
        return dp[left][right] = ans;
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size() ;
        dp.resize(n+1 ,vector<int>(n+1,-1));
        int ans = 0;
        ans = max(ans , 1+ solve(nums,  2 , n-1, nums[0] + nums[1]));
        ans = max(ans , 1+ solve(nums, 0 , n -3, nums[n-1] + nums[n-2]));
        ans = max(ans , 1+ solve(nums,   1 , n-2, nums[0] + nums[n-1]));
        return ans;
    }
};
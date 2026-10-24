class Solution {
public:
    // bool solve(vector<int> &nums, int ind, vector<int>&dp){
    //     int n = nums.size();
    //     if (ind == n-1) return true;
    //     if (ind >= n) return false;
    //     if (dp[ind] != -1) return dp[ind];
    //     bool ans = false;
    //     for (int i = 1;i<=nums[ind];i++){
    //         ans = ans | solve(nums, ind + i, dp);
    //     }
    //     return dp[ind] =  ans ;

    // }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i= 0;i<nums.size();i++){
            if (i >maxi ) return false;
            maxi = max(maxi , i+nums[i]);
        }
        return true;
    }
};
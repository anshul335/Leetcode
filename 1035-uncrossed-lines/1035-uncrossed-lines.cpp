class Solution {
public:
    int dp[501][501];
    int solve (vector<int>& nums1,vector<int>&nums2, int ind1,int ind2){
        int n = nums1.size();
        int m = nums2.size();
        if (ind1 >= n || ind2 >= m)return 0;
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int ans = 0;
        if (nums1[ind1] == nums2[ind2]){
            ans = 1 + solve(nums1,nums2,ind1+1,ind2+1);
        }
        else {
            ans = max(solve(nums1, nums2, ind1+1, ind2) , solve(nums1, nums2, ind1, ind2+1));
        }
        return dp[ind1][ind2] = ans ;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums1, nums2, 0,0);
    }
};
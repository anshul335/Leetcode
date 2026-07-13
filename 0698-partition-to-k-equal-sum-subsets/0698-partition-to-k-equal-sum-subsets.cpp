class Solution {
public:
    bool solve (vector<int> &nums,int k,int ind,vector<int>&vis , int target , int currSum){
        if (k==1) return true;
        if (currSum == target) return solve (nums, k-1 , 0,vis,target,0);
        int n = nums.size();
        for (int j = ind ;j<n ;j++){
            if (vis[j] || currSum + nums[j] > target) continue;
            vis[j] = true;
            if (solve (nums,k,j +1 ,vis,target, currSum + nums[j])){
                return true;
            }
            vis[j] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0LL);

        if (nums.size() < k  || sum % k != 0) return false;
        vector<int> vis (nums.size(),0);
        return solve (nums , k, 0,vis, sum/k ,0); 
    }
};
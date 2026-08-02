class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int maxi = 0;
        for (int i =0;i<nums.size();i++){
            ans += max(maxi - nums[i] , 0);
            maxi = max(nums[i], maxi) + 1;
        }
        return ans;
    }
};
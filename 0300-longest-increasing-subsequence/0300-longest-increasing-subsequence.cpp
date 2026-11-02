class Solution {
public:

    // Tabu 

    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for (int i =0;i<nums.size();i++){
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            if(it != lis.end()){
                *it = nums[i];
            }
            else {
                lis.push_back(nums[i]);
            }
        }
            return lis.size() ;
    }
};
class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int low = 0;
        int high = nums.size()-1;
        while (low <= high){
            if (nums[low] + nums[high]<=limit){
                ans ++;
                low ++;
                high--;
            }
            else {
                high--;
                ans++;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        vector<int>arr;
        arr.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) {
                count++;
                arr.push_back(nums[i]);
            }
        }
        nums=arr;
        return count;
    }
};
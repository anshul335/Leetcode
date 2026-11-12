class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evenIndex = 0;
        for (int i =0;i<nums.size();i++){
            if (nums[i] % 2==0){
                if (i == evenIndex){
                    evenIndex++;
                }
                else {
                    swap(nums[evenIndex], nums[i]);
                    evenIndex++;
                }
            }
        }
        return nums;
    }
};
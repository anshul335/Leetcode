class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                if(nums[i]+nums[low]+nums[high]==0){
                     ans.push_back({nums[i],nums[low],nums[high]});
                     high--;
                     low++;
                      while (low < high && nums[low] == nums[low - 1])
                     low++;
                     while (low < high && nums[high] == nums[high + 1])
                     high--;
                }
                else if(nums[i]+nums[low]+nums[high]>0){
                    
                     high--;
                     
                }
                if(nums[i]+nums[low]+nums[high]<0){
                     
              
                     low++;
                }
            }
        }
        return ans;
    }
};
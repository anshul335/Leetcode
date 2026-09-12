class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX/2;
        for(int i=0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(abs(sum-target)<abs(ans-target)){
                    ans=sum;
                }
                if(sum<target) low++;
                else if(sum>target) high--;
                else return sum;
            }
        }
        return ans;
    }
};
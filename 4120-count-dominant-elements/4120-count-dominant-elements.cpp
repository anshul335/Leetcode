class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int ans =0;
        for (int i =0;i<nums.size();i++){
            int sum = 0;
            int count = 0;
            if (i>=1) {
                sum += nums[i-1]; 
                count++;
            }
            if (i < nums.size()-1){
                sum += nums[i+1]; 
                count++;
            }

            
            if (count == 0 || ((nums[i] * count) >=  sum) ) ans++;
        }
        return ans;
    }
};
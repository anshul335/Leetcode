class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans = 0;
        vector<long long>prefix(nums.size());
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            prefix[i] = __gcd(nums[i],maxi);
        }
        sort(prefix.begin(),prefix.end());
        int left = 0;
        int right = prefix.size()-1;
        while(left<right){
            ans+= (__gcd(prefix[left],prefix[right]));
            left++;
            right--;
        } 
        return ans ;
    }
};
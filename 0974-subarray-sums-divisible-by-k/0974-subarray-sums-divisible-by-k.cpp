class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int sum = 0;
        int ans = 0;
        for (int i =0;i<nums.size();i++){
            sum += nums[i];
            int remain = ((sum % k) + k) % k;
            ans += mpp[remain];
            mpp[remain]++;
        }
        return ans;
    }
};
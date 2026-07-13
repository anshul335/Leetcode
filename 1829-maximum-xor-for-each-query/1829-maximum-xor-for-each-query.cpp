class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int limit = pow(2,maximumBit) -1;
        int n = nums.size();
        int Xor = 0;
        for (auto & it : nums) Xor ^= it;
        vector<int>ans ;
        for(int i =0;i<n;i++){
            ans.push_back(Xor ^ limit);
            Xor ^= nums[n-i-1];
        }
        return ans ;
    }
};
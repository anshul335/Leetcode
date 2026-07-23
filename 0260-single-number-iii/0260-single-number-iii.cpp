class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long Xor = 0;
        for (auto it : nums) Xor ^= it;

        long long  rightOne = (Xor & (Xor-1)) ^Xor;
        int bucket1 = 0;
        int bucket2 = 0;
        for (auto it : nums){
            if (it & rightOne) bucket1 ^= it;
            else bucket2 ^= it;
        }
        return {bucket1, bucket2};
    }
};
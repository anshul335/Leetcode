class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>bits(32, 0);
        for (int i =0;i<nums.size();i++){
            for (int j =0;j<=31;j++){
                if (nums[i] & (1<< j)) bits[j]++;
            }
        }
        const int MOD = 1e9+ 7;
        int ans = 0;
        for (int i =0;i<k;i++){
            int x = 0;
            for (int j =31;j>=0;j--){
                if (bits[j] >0){
                    x |= (1<< j);
                    bits[j]--;
                }

            }

            ans = (ans + (1LL * x * x) % MOD) % MOD;
        }
        return ans ;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int ans = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int sum = 0;
        for (int num : arr){
            sum = (sum + num) % 2;
            if (sum == 1){
                ans = (ans + mpp[0]) % MOD;
            }
            else {
                ans = (ans + mpp[1]) % MOD;
            }
            mpp[sum]++;
        }
        return ans ;
    }
};
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> mpp(n,0);
        for (auto it : requests){
            mpp[it[0]]++;
            if (it[1]+1< n )mpp[it[1]+1]--;
        }
        for (int i =1;i<n;i++){
            mpp[i] += mpp[i-1];
        }
        int ans = 0;
        sort(nums.begin(), nums.end());
        sort(mpp.begin(), mpp.end());
        int mod = 1e9+7;
        for (int i = n-1;i>=0;i--){
            ans = (ans + (1LL* nums[i] * mpp[i]) % mod) % mod;
        }
        return ans ;
    }
};
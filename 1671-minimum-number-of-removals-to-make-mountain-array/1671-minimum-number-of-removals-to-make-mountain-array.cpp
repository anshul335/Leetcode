class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> LISLen(n);
        vector<int> LIS;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(LIS.begin(), LIS.end(), nums[i]);
            int len = (it - LIS.begin()) + 1; 
            if (it != LIS.end()) {
                *it = nums[i];
            } else {
                LIS.push_back(nums[i]);
            }
            LISLen[i] = len; 
        }
        
        vector<int> LDSLen(n);
        vector<int> LDS;
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(LDS.begin(), LDS.end(), nums[i]);
            int len = (it - LDS.begin()) + 1; 
            if (it != LDS.end()) {
                *it = nums[i];
            } else {
                LDS.push_back(nums[i]);
            }
            LDSLen[i] = len; 
        }
        
        int ans = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            if (LISLen[i] > 1 && LDSLen[i] > 1) { 
                ans = min(ans, n - LISLen[i] - LDSLen[i] + 1);
            }
        }
        
        return ans;
    }
};
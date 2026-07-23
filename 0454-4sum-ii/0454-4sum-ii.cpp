class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mpp;
        for (auto it1 : nums1){
            for (auto it2 : nums2){
                mpp[it1 + it2] ++;
            }
        }
        int ans = 0;
        for (auto it1 : nums3){
            for (auto it2 : nums4){
                ans += mpp[-(it1 + it2)];
            }
        }
        return ans ;
    }
};
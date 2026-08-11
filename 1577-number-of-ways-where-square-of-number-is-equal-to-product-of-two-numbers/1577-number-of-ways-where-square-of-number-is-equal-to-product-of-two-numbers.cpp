class Solution {
public:
    int solve (vector<int>& nums1, vector<int> & nums2){
        int ans =0;
        for (int i =0;i<nums1.size();i++){
            long long req = 1LL*nums1[i] * nums1[i];
            
            unordered_map<int,int> mpp;
            for (int i =0;i<nums2.size();i++){
                if (req % nums2 [i] == 0){
                    int need = req/nums2[i];
                    ans += mpp[need];
                    mpp[nums2[i]] ++;
                }
            }
        }
        return ans ;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int ans = 0;
        ans += solve (nums1,nums2);
        ans += solve (nums2,nums1);
        return ans ;
    }
};
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxEle = *max_element(nums.begin(),nums.end());
        vector<long long>count(maxEle+1,0);
        for (auto & x : nums) count[x] ++;
        vector<long long>div(maxEle+1,0);
        for (int i =1;i<=maxEle;i++){
            for (int j = i;j<=maxEle;j+=i){
                div[i] += count[j];
            }
        }
        vector<long long>gcdCount(maxEle+1,0);
        for (int i = maxEle ;i>=1;i--){
            
            gcdCount[i] = (div[i] * (div[i]-1))/2;

            for (int j = 2*i;j<=maxEle;j+=i){
                gcdCount[i] -= gcdCount[j];
            }
        }
        vector<long long>pref(maxEle+1,0);
        for (int i = 1;i<=maxEle;i++) pref[i] = pref[i-1] + gcdCount[i];
        vector<int>ans;
        for (auto & q: queries){
            auto it = lower_bound(pref.begin()+1,pref.end(),q+1) - pref.begin();
            ans.push_back(it);
        }
        return ans;
    }

};
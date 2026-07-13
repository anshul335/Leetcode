class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for (auto &it :nums) mpp[it]++;
        vector<vector<int>> ans;
        while (!mpp.empty()){
            vector<int>curr ;
            for (auto it = mpp.begin(); it != mpp.end(); ) {
                curr.push_back(it->first);
                it->second--;

                if (it->second == 0)
                    it = mpp.erase(it);
                else
                    ++it;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
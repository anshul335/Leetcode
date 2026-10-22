class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> ans;
        map<int,long long> mpp;
        for (auto it : segments){
            mpp[it[0]]+=it[2];
            mpp[it[1]]-=it[2];
        }
        int start = -1;
        long long sum = 0;
        for (auto it : mpp){
            int end = it.first;
            if (start != -1 && sum > 0){
                ans.push_back({start, end, sum});

            }
            sum += it.second;
            start = end;
        }
        return ans ;
    }
};
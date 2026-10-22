class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mpp;
        for (auto & it : trips){
            mpp[it[1]]+=it[0];
            mpp[it[2]]-=it[0];
        }
        int currCount = 0;
        for (auto &it: mpp){
            currCount += it.second;
            if (currCount > capacity) return false;
        }
        return true;

    }
};
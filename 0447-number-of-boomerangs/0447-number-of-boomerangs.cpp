class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto p1 : points){
            unordered_map<int,int>mpp;
            for (auto p2 : points){
                if (p1 == p2) continue;
                int dis = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
                mpp[dis]++;
            }
            for (auto it : mpp){
                ans += (it.second) * (it.second-1);
            }
        }
        return ans;
    }
};
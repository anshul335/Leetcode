class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n<=2) return n;
        int ans = 0;
        for (auto & p1 : points){
            unordered_map<double, int> mpp;
            for (auto & p2 : points){
                if(p1 == p2) continue;
                double slop = 0;
                if (p2[0] == p1[0]) slop = INT_MAX;
                else {
                    slop = (double)(p2[1] - p1[1])/(p2[0]-p1[0]);
                }
                mpp[slop]++;
                ans = max(ans, mpp[slop]+1);
            }
        }
        return ans ;
    }
};
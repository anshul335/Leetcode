class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans ;
        for (auto it : queries){
            int x = it[0];
            int y = it[1];
            int rad = it[2];
            int count = 0;
            for (auto p : points){
                int dx = x - p[0];
                int dy = y - p[1];

                if (dx * dx + dy * dy <= rad * rad) count++;
            }
            ans.push_back(count);
        }
        return ans ;
    }
};
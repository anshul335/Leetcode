class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> dp;
        for (int i =0;i<obstacles.size();i++){
            int ind = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
            if (ind == dp.size()) {
                dp.push_back(obstacles[i]);
            }
            else {
                dp[ind] = obstacles[i];
            }
            ans.push_back(ind+1);
        }
        return ans ;
    }
};
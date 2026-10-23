class Solution {
public:
    int getNextIndex(vector<vector<int>> & jobs , int left , int currJobEnd){
        int n = jobs.size();
        int right = n -1;
        int res = n;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (jobs[mid][0] >= currJobEnd){
                res = mid;
                right = mid-1;

            }
            else {
                left = mid+1;
            }
        }
        return res;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i =0;i<startTime.size();i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        int n = jobs.size();
        vector<int> dp(n + 1, 0);
        for (int ind = n-1;ind>=0;ind--){
            int next = getNextIndex(jobs, ind+1, jobs[ind][1]);
            int take = jobs[ind][2] + dp[next];
            int notTake = dp[ind+1];
            dp[ind] =  max(take , notTake);
        }
        return dp[0];
    }
};
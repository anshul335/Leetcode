class Solution {
public:
    int dp[100005];
    int getNextIndex(vector<vector<int>> & jobs , int left , int currJobEnd){
        int n = jobs.size();
        int right = n -1;
        int res = n+1;
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
    int solve( int ind ,vector<vector<int>>&jobs ){
        int n = jobs.size();
        if (ind >=n) return 0;
        if (dp[ind] != -1) return dp[ind];
        int take = 0;
        int notTake = 0;
        int next = getNextIndex(jobs, ind+1, jobs[ind][1]);
        take = jobs[ind][2] + solve(next , jobs);
        notTake = solve(ind+1,jobs);
        return dp[ind] =  max(take , notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        memset(dp, -1,sizeof(dp));
        for (int i =0;i<startTime.size();i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        return solve (0,jobs);
    }
};
class Solution {
public:
    long long recursion (vector<vector<int>>&arr, int ind,int n,vector<long long>&dp){
        
        if (ind>=n) return 0;
        if (dp[ind]!=-1) return dp[ind];
        long long take = 0;
        long long notTake = 0;
        take += arr[ind][0] + recursion(arr,ind+arr[ind][1]+1, n,dp);
        notTake = recursion(arr,ind+1,n,dp);
        
        return dp[ind]=max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long>dp(n,-1);
        return recursion(q,0,n,dp);
    }
};
class Solution {
public:
    const int MOD = 1e9+7;
    int solve(string &s , int ind , int k, vector<int>&dp){
        int n = s.length();
        if (ind >=n) return 1;
        if (s[ind] == '0') return 0;
        if (dp[ind] !=-1) return dp[ind];
        int ans = 0;
        long long num = 0;
        for (int i = ind;i<n;i++){
            num *= 10 ;
            num += (s[i] - '0');
            if (num >=1 && num <= k){
                ans =  (ans + solve(s, i+1, k,dp))%MOD;
            }
            if (num > k) break;
        }
        return dp[ind] = ans ;
    }
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return solve(s, 0, k,dp);
    }
};
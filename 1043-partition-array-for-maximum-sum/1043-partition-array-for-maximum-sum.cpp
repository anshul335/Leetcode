class Solution {
public:
    // int memo[501];
    // int solve (vector<int>&arr,int ind,int k){
    //     int n = arr.size() ;
    //     if (ind == n)
    //         return 0;
    //     if (memo[ind] != -1) return memo[ind];
    //     int ans = 0;
    //     int maxi = 0;
    //     for (int i =ind;i< min(n, ind + k);i++){
    //         maxi = max(maxi, arr[i]);
    //         ans = max(ans,( i - ind +1) * maxi + solve (arr,i+1,k) );
    //     }
    //     return memo[ind]= ans;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // memset(memo,-1,sizeof(memo));
        // return solve (arr, 0,k);
        int n = arr.size();
        vector<int> dp (n+1 , 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            int ans = 0;
            int maxi = 0;

            for (int j = ind; j < min(n, ind + k); j++) {
                maxi = max(maxi, arr[j]);
                ans = max(ans,
                          (j - ind + 1) * maxi + dp[j + 1]);
            }

            dp[ind] = ans;
        }
        return dp[0];

    }
};
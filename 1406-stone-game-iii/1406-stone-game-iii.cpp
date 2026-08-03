class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        for (int i = n-1;i>=0;i--){
            int ans  = INT_MIN;
            int currSum = 0;
            for (int j = i;j<min(n,i+3);j++){
                currSum += nums[j];
                ans = max(ans, currSum - dp[j+1]); 
            }
            dp[i] = ans;
        }
        if (dp[0]>0) return "Alice";
        else if (dp[0]<0) return "Bob";
        return "Tie";
    }
};
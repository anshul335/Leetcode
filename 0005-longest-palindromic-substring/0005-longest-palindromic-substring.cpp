class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        vector<vector<int>>dp(n +1 ,vector<int> (n+1,false));

        for (int i =0;i<n;i++){
            dp[i][i] = true;
        }
        int start = 0;
        int end = 0;
        int maxi = 0;
        for (int i =0;i<n;i++){
            for (int j = 0;j<i ;j++){
                if (s[i] == s[j] && (i - j <=2 || dp[j+1][i-1] == true) ){
                    dp[j][i] = true;
                    if (i - j + 1> maxi){
                        maxi = i - j+1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr( start , end - start +1 );
    }
};
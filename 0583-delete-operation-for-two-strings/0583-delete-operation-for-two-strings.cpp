class Solution {
public:
    // int memo[501][501];
    // int solve(string& word1, string& word2, int i, int j) {
    //     if (i == word1.length() && j == word2.length()) {
    //         return 0;
    //     }
    //     if (memo[i][j] != -1)
    //         return memo[i][j];
    //     int isEqual = INT_MAX;
    //     if (i < word1.length() && j < word2.length() && word1[i] == word2[j])
    //     {
    //         isEqual = solve(word1, word2, i + 1, j + 1);
    //     }
    //     int first = INT_MAX;
    //     int second = INT_MAX;
    //     if (i < word1.length()) {
    //         first = 1 + solve(word1, word2, i + 1, j);
    //     }
    //     if (j < word2.length()) {
    //         second = 1 + solve(word1, word2, i, j + 1);
    //     }
    //     return memo[i][j] = min({isEqual, first, second});
    // }
    int minDistance(string word1, string word2) {
        // memset(memo,-1,sizeof(memo));
        // return solve(word1, word2, 0, 0);
        int n = word1.length();
        int m = word2.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int>last(m+1,0);
        for (int j = 0; j <= m; j++)last[j] = m - j;

        // for (int j = 0; j <= m; j++)dp[n][j] = m - j;

        for (int i = n - 1; i >= 0; i--) {
            vector<int>curr(m+1,0);
            curr[m] = n - i;
            for (int j = m - 1; j >= 0; j--) {
                int isEqual = INT_MAX;
                if (word1[i] == word2[j]) {
                    isEqual = last[j + 1];
                }
                int first = INT_MAX;
                int second = INT_MAX;
                if (i < word1.length()) {
                    first = 1 + last[j];
                }
                if (j < word2.length()) {
                    second = 1 + curr[j + 1];
                }
                curr[j] = min({isEqual, first, second});
            }
            last = curr;
        }
        return last[0];
    }
};
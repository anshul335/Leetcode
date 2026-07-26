class Solution {
public:
    int memo[501][501];
    int solve (string &word1 , string &word2 , int i, int j){
        if (i == word1.length() && j == word2.length()) {
            return 0;
        }
        if (memo[i][j] != -1) return memo[i][j];
        int isEqual = INT_MAX;
        if (i<word1.length() && j < word2.length() &&word1[i] == word2[j]){
            isEqual = solve (word1, word2, i+1,j+1);
        }
        int first = INT_MAX;
        int second = INT_MAX;
        if (i< word1.length()){
            first = 1+solve (word1, word2, i+1,j );
        }
        if (j< word2.length()){
            second =1+ solve (word1,word2,i,j+1);
        }
        return memo[i][j] = min({isEqual , first, second});
    }
    int minDistance(string word1, string word2) {
        memset(memo,-1,sizeof(memo));
        return solve(word1, word2, 0, 0);
    }
};
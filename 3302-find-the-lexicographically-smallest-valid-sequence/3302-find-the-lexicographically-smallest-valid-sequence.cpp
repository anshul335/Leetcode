class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>suff(m,-1);
        for (int i = n-1, j = m-1;i>=0;i--){
            if (j>=0 && word1[i] == word2[j]){
                suff[j] = i;
                j--;
            }
        }
        vector<int>ans;
        int take = 0;
        for (int i =0,j =0;i<n && j<m;i++){
            if (word1[i]==word2[j] || (take == 0 && ( j == m-1||i< suff[j+1] ))){
                ans.push_back(i);
                if (word1[i] != word2[j]){
                    take ++ ;
                }
                j++;
            }
            if (ans.size()== m) return ans ;
        }
        return {};
    }
};
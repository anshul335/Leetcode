class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mpp;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i =0;i<n;i++){
            string curr ="";
            string invertCurr ="";
            for (int j =0;j<m;j++){
                curr += matrix[i][j] + '0';
                invertCurr += (matrix[i][j]^1) +'0';
            }
            mpp[curr]++;
            mpp[invertCurr]++;

        }
        int ans = 0;
        for (auto it : mpp){
            ans = max(ans,it.second);
        }
        return ans;
    }
};
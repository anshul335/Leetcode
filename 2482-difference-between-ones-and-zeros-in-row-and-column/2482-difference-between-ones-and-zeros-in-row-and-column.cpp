class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>rowOne (m,0);
        vector<int>rowZero(m,0);
        vector<int>colOne (n,0);
        vector<int>colZero(n,0);
        for (int i =0;i<m;i++){
            for (int j =0;j<n;j++){
                if (grid[i][j]==0){
                    rowZero[i] ++;
                    colZero[j] ++;
                }
                else {
                    rowOne[i] ++ ;
                    colOne[j]++;
                }
            }
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        for (int i =0;i<m;i++){
            for (int j =0;j<n;j++){
                ans[i][j] = rowOne[i] + colOne[j] - rowZero[i] - colZero[j];
            }
        }
        return ans;
    }
};
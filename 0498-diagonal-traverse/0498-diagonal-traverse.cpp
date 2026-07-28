class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool flag = true;
        vector<int>ans;
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j =0;
        while (ans.size() < n*m){
            ans.push_back(mat[i][j]);
            if (flag){
                if (j == m-1){
                    i++;
                    flag= false;
                }
                else if (i==0){
                    j++;
                    flag = false;
                }
                else {
                    i--;
                    j++;
                }

            }
            else {
                 if (i == n - 1) {
                    j++;
                    flag = true;
                }
                else if (j == 0) {
                    i++;
                    flag = true;
                }
                else {
                    i++;
                    j--;
                }
            }
        }
        return ans ;
    }
};
class Solution {
public:
    int dp[105][105][205];
    bool solve (vector<vector<char >> & grid ,int i , int j , int count){
        int n = grid.size();
        int m = grid[0].size();
        if (i == n -1 &&  j == m-1) {
            if (grid[i][j] == ')') count--;
            else count ++;
            return count == 0;
        }
        if (dp[i][j][count] != -1) return dp[i][j][count];
        bool right = false;
        bool down = false;
        if (j < m-1){
            int newCount = count;
            if (grid[i][j] == ')') newCount--;
            else newCount ++;
            
            if (newCount >=0)right = solve (grid, i, j+1,newCount );
        }
        if (i < n -1 ){
            int newCount = count;
            if (grid[i][j] == ')') newCount--;
            else newCount ++;
            if (newCount >=0) down = solve (grid, i+1, j , newCount);
            
        }

        return dp[i][j][count] =  right || down ;
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp , -1, sizeof (dp));
        return solve (grid, 0, 0 , 0);
    }
};
class Solution {
public:

    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
        vector<int> dir = {-1, 0, 1};

        for (int x = n - 1; x >= 0; x--) {
            for (int y1 = 0; y1 < m; y1++) {
                for (int y2 = 0; y2 < m; y2++) {
                    int ans = 0;
                    if (y1 == y2) {
                        ans += grid[x][y1];
                    } else {
                        ans = grid[x][y1] + grid[x][y2];
                    }
                    int next = 0;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            int ny1 = y1 + dir[i];
                            int ny2 = y2 + dir[j];
                            if (ny1 >= 0 && ny2 >= 0 && ny1 < m && ny2 < m) {
                                next = max(next, dp[x + 1][ny1][ny2]);
                            }
                        }
                    }
                    dp[x][y1][y2] = ans+ next;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};
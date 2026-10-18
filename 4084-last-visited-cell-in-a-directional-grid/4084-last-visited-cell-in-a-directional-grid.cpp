class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int x = 0;
        int y = 0;
        vector<int> ans ;
        while(true){
            if (x <0 || x >= n || y <0 || y >= m) break;
            if (visited[x][y] == true) break;

            visited[x][y] = true;
            ans = {x,y};
            if (grid[x][y] == 'L') y--;
            else if (grid[x][y] == 'R') y++;
            else if (grid[x][y]=='D') x++;
            else x--; 
            
        }
        return ans ;
        
    }
};
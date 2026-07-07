class Solution {
public:
    vector<vector<int>>direction = {{-1,0},{1,0},{0,-1},{0,1}};
    bool solve (vector<vector<int>>& vis , vector<vector<int>>&grid,int x,int y,int m,int n){
        if (x == m-1 || x==0 || y == 0|| y == n-1) return false;
        
        bool ans = true;
        vis[x][y] = true;
        for (auto dir : direction ){
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (vis[nx][ny] == true || grid[nx][ny] == 1) continue;
            ans = ans & solve(vis,grid,nx,ny,m,n);//isme boundary khan check kri h?
        }
        
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      vector<vector<int>>vis(m,vector<int>(n,0));
      int ans=0;
      for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(grid[i][j]==0&&vis[i][j]==0){
                
                if(solve(vis,grid,i,j,m,n)) ans++;
            }
        }
      }
      return ans; 
    }
};
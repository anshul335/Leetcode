class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        vector<int>dx = {-1,0,1,0};
        vector<int>dy = {0,-1,0,1};
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            int time = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if(row==n-1&&col==m-1) return time;
            if(visited[row][col]) continue;
            visited[row][col] = true;
            for(int i =0;i<4;i++){
                int newRow = row+dx[i];
                int newCol = col+dy[i];
                if(newRow<0||newCol<0||newRow>=n||newCol>=m)continue;
                int wait = ((grid[newRow][newCol]-time)%2==0);
                pq.push({max(grid[newRow][newCol]+wait,time+1),newRow,newCol});
            }


        }
        return -1;
    }
};
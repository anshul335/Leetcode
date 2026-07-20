class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        int n= r * c;
        k = k%n;
        if (k==0) return grid;
    
        auto solve = [&] ( int i , int j){
            while (i<j){
                swap(grid[i/c][i%c],grid[j/c][j%c]);
                i++;
                j--;
            }
        };

        solve (0,n-1);
        solve (0,k-1);
        solve (k, n-1);

        return grid;
    }
};
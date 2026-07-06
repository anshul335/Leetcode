/*
kuch socha?helllo??? ?Soch raha hu  kya socha h kaise karoge ?tumne soch liya
 Nahi 
 isme simultaneouly aag lgei to multisource bfs lgegi wese to Ha wo tho bata h mujhe 
 isme binary search ki help se nikalnegy agr ki x min possible h ya nhi to wo multi source bfs se hi kr lnegy ha ese kar sakte h 
 pr binary search ki max limit kya hogi 
 jese min 0 hogi aur 0 p not possible hua to -1 aur max p not possible hua to 1e9 shyd
 max limit m *n ho skti h? me bhi yahi sich raha tha ki m*n hi hogi 1e9 to nhi le skte kyunki kyu nhi le sakte 1e9 se aa jayega answer , max tho kuch bhi le apan 
 kyunki 1e9 ki help se hme check krna pda to tle aa jayega aur 1e9 wala case possible h aree nahi aayega i think 
 hm check kese krengey? jjese x k liye check kr rhe hn to phle x min k baad ki situation create kr lenegy aur fir jane ki koshisk krengey??agr aese kra to 1e9 p tle aayega apne ko ye hi tho calculate karna ki kitne dher tak wo start me h tho nhi ek baar code likh kar dekhte h fir pata chalega 
 hme y dekhna h na ki agr wo kitne max minutes tk initail pos p rukke bhi safely phauch jayega ha 
 to kese krogey x k liye checkkk phle x min k liye use whan rukwake aur then?aese? Ha thik h
*/
class Solution {
public:
    vector<vector<int>> fireprecompute(vector<vector<int>>& grid ){
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visByFire(m,vector<int>(n,INT_MAX));
        for (int i =0;i<m;i++){
            for (int j = 0;j<n;j++){
                if (grid[i][j]==1){
                    q.push({i,j});
                    visByFire[i][j] = 0;
                }
            }
        }
        vector<vector<int>>direction = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for( auto d: direction){
                    int ii=i+d[0];
                    int jj=j+d[1]; 
                    if (ii>=0&& jj>=0 && ii<m && jj< n && grid[ii][jj]==0 && visByFire[ii][jj] > visByFire[i][j]+1){
                        visByFire[ii][jj]=visByFire[i][j] +1 ;
                        q.push({ii,jj});                       
                    }
                }
        }
        return visByFire;
        
    }
    bool isPossible(int mid,vector<vector<int>>&fire,vector<vector<int>>& grid){
        int m=fire.size();
        int n=fire[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = 1;
        int time = mid;
        if (fire[0][0]<=mid) return false;
        vector<vector<int>>direction = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            int sz = q.size();
            while (sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x==m-1 && y == n-1) return true;
                for (auto it : direction){
                    int nx = x + it[0];
                    int ny = y + it[1];
                    if (nx<0 || ny< 0 || nx>=m || ny>=n) continue;
                    if (nx== m-1 && ny == n-1 ) {
                        if (fire[nx][ny]<time+1) continue;
                    }
                    else {
                        if (fire[nx][ny]<=time+1) continue;
                    }
                    if (grid[nx][ny]==2) continue;
                    if (vis[nx][ny]==0){
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
            time ++;
        }
        return false;
    }//kya problem h? Pata nhi 
    int maximumMinutes(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();   
    
        int low = 0;
        int high = 1e9;
        int ans = -1;//1e9 m problem h nhi gpt bol rha h Aree code tho chla gaya but abb wrong ans aa raha h aage tle aajayega last m ab
        vector<vector<int>>fire = fireprecompute(grid);
        while (low <= high){
            int mid = low+(high-low)/2;
            if(isPossible(mid,fire,grid)){
                ans = mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans ;   
    
    }
}; // Gpt karke dekhno na kha tle aa raha h 
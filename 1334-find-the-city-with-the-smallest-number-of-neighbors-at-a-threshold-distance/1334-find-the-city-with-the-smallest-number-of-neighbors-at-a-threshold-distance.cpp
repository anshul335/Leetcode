class Solution {  
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dis[u][v] = w;
            dis[v][u] = w;
            
        }
        for (int via = 0;via<n;via++){
            for (int u = 0;u<n;u++){
                for (int v = 0;v<n;v++){
                    if (u == v) dis[u][v]  = 0;
                    if (dis[u][via]==INT_MAX|| dis[via][v] == INT_MAX) continue;
                    dis[u][v] = min(dis[u][v], dis[u][via]+ dis[via][v]);
                }
            }
        }

        vector<int>arr(n);
        for(int i=0;i<n;++i){
            int count=0;
            for(int j=0;j<n;++j){
                if(dis[i][j]<=distanceThreshold)count++;
            }
            arr[i]=count;
        }
        
        int mini=INT_MAX;
        int city=-1;
        for(int i=0;i<n;++i){
            if(arr[i]<=mini){
                mini=arr[i];
                city=i;
            }
        }
        
        return city;
    }
};
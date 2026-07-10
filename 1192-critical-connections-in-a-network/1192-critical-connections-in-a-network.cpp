class Solution {
public:
    void dfs(int node ,int parent,vector<vector<int>>&adj,vector<int>& discover ,vector<int> & low,vector<bool>& vis, vector<vector<int>>& bridge,int &count){
        discover[node] =  low [node] = count;
        vis[node] = true;
        for (int j = 0;j<adj[node].size();j++){
            int neigh = adj[node][j];
            if (neigh == parent) continue;
            else if (vis[neigh]) {
                low[node] = min(low[node],low[neigh]);
            }
            else {
                count++;
                dfs(neigh,node,adj,discover,low,vis,bridge,count);
                // bridge checking
                if (low[neigh]>discover[node]){
                    vector<int>temp ;
                    temp.push_back(node);
                    temp.push_back(neigh);
                    bridge.push_back(temp);
                }
                low [node] = min(low[node],low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for (auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>Bridges;
        vector<int>discover(n);
        vector<int>low(n);
        vector<bool>vis(n,false);
        int count = 1;
        dfs(0,-1,adj,discover,low,vis,Bridges,count);
        return Bridges;
    }
};
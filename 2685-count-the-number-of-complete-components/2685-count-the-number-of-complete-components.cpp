class Solution {
public:
    void bfs(int node,vector<int>&arr){
        queue<int> q;
        q.push(node);
        vis[node]=true;

        while(!q.empty()){
            int n=q.front();
            q.pop();
            arr.push_back(n);
            for(auto it:adj[n]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
    }
    vector<vector<int>> adj;
    vector<int>vis;
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.assign(n,vector<int>());
        vis.assign(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans =0;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                vector<int> arr;
                bfs(i,arr);
                bool flag = true;
                for(auto it:arr){
                    if(adj[it].size()!=arr.size()-1){
                        flag = false;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};
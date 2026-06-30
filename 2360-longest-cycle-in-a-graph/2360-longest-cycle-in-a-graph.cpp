class Solution {
public:
    int ans;
    void dfs(vector<int>&edges,int node,vector<bool>&inRecursion,vector<bool>&visited,vector<int>&count){
        if (node!=-1){
            visited[node] = true;
            inRecursion[node] = true;
            int v = edges[node];
            if (v!=-1&&!visited[v]){
                count[v] = count[node] + 1;
                dfs(edges,v,inRecursion,visited,count);
            }
            else if (v!=-1&&inRecursion[v]==true){
                ans = max(ans,count[node]-count[v]+1);
            }
            inRecursion[node] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool>inRecursion(n,false);
        vector<bool>visited(n,false);
        vector<int>count(n,1);
        ans = -1;
        for (int i =0;i<n;i++){
            if (visited[i]==0){
                dfs(edges,i,inRecursion,visited,count);
            }
        }
        return ans ;
    }
};
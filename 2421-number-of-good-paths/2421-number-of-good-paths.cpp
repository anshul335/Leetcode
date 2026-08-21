class DSU{
    public :
    vector<int>parent;
    vector<int>rank;
    DSU(int n ){
        parent.resize(n);
        rank.resize(n);
        for (int i =0;i<n;i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
    }
    int find(int p){
        if (parent[p] == p) return p;
        return parent[p] = find(parent[p]);
    }
    void Union(int u, int v){
        int u_par = find(u);
        int v_par = find(v);
        if (u_par == v_par){
            return ;
        }
        else if (rank[u_par]<rank[v_par]){
            parent[u_par] = v_par; 
        }
        else if (rank[v_par]<rank[u_par]){
            parent[v_par] = u_par;

        }
        else {
            parent[v_par] = u_par;
            rank[u_par] ++;
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>>adjList(n);
        for (auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        map<int,vector<int>> valueToNode;
        for (int i =0;i<n;i++){
            valueToNode[vals[i]].push_back(i);
        }
        DSU dsu(n);
        vector<bool> isActive (n,false);
        int ans = n;
        for (auto it : valueToNode){
            vector<int>currNode = it.second;
            for (auto u : currNode){
                for (auto v : adjList[u] ){
                    if (isActive[v] == true){
                        dsu.Union(u,v);
                    }
                }
                isActive[u]= true;
            }
            vector<int>currParent;
            for (auto it : currNode){
                currParent.push_back(dsu.find(it));
            }
            sort(currParent.begin(),currParent.end());
            int size = currParent.size();
            int j =0;
            
            while (j< size){
                int count = 0;
                int curr = currParent[j];
                while (j<size && curr == currParent[j]){
                    count++;
                    j++;
                }
                
                ans += 1LL * (count ) * (count -1)/2;
            }
        }
        return ans ;
    }
};
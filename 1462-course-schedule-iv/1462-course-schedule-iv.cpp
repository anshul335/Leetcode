class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>>adj(n);
        for (auto it : pre){
            adj[it[1]].insert(it[0]);
        }
        for (int i =0;i<n;i++){
            for (int j =0;j<n;j++){
                if(adj[j].count(i)) adj[j].insert(adj[i].begin(),adj[i].end());
            }
        }
        vector<bool>ans;
        for (auto it : queries){
            ans.push_back(adj[it[1]].count(it[0])>0) ;
        }
        return ans ;
    }
};
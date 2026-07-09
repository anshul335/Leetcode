class DSU{
    public :
        vector<int>parent;
        vector<int>rank;
        DSU(int n){
            parent.resize(n,0);
            rank.resize(n,1);
            for (int i =0;i<n;i++) parent[i] = i;
        }
        int find(int i){
            if(parent[i]==i) return i;
            return parent[i] = find(parent[i]);
        }
        void unite(int u,int v){
            int uPar = find(u);
            int vPar = find(v);
            if (uPar == vPar) return ;
            if (rank[uPar]>rank[vPar]){
                parent[vPar] = uPar;
            }
            else if (rank[vPar]>rank[uPar]){
                parent[uPar] = vPar;
            }
            else {
                parent[vPar] = uPar;
                rank[uPar]++;
            }
        }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu (n);
        for (int i = 1;i<n;i++){
            if (abs(nums[i]-nums[i-1])<=maxDiff) dsu.unite(i,i-1);
        }
        vector<bool> ans (queries.size(),false);
        for (int i =0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if (dsu.find(u) == dsu.find(v)) {
                ans[i] = true;
            }
        }
        return ans;

    }
};
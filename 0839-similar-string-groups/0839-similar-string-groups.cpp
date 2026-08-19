class DSU{
    public :
    vector<int>parent;
    DSU(int n ){
        parent.resize(n);
        for (int i =0 ;i<n;i++) parent[i] = i;
    }
    int find (int i){
        if (parent[i] == i)return i;
        return parent[i] = find(parent[i]);
    }
    void Union(int x , int y){
        int x_par = find(x);
        int y_par = find(y);
        if (x_par == y_par) return ;
        parent[x_par] = y_par;
    }

};
class Solution {
public:
    bool isSimilar(string &a , string & b){
        int count = 0;
        for (int i =0;i<a.size();i++){
            if (a[i] != b[i]) count++;
        }
        return count <= 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        DSU *dsu = new DSU(n);
        for (int i =0;i<strs.size();i++){
            for (int j =0;j<strs.size();j++){
                if (isSimilar(strs[i],strs[j])) {
                    dsu->Union(i,j);
                }
            }
        }
        int ans = 0;
        for (int i =0;i<n;i++){
            if (dsu->find(i) == i) ans++;
        }
        return ans;
    }
};
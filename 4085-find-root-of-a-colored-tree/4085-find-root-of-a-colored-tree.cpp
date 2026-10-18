class Solution {
public:
    int findColor(char ch){
        if (ch == 'R') return 0;
        else if (ch == 'B') return 1;
        return 2;
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.length();
        vector<int> outDegree (n,0);
        vector<int>inDegree(n,0);
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            int cu = findColor(colors[u]);
            int cv = findColor(colors[v]);
            if (cu == cv) return -1;
            if ((cv - cu + 3) % 3== 1){
                inDegree[v]++;
                outDegree[u]++;
            }
            else {
                inDegree[u]++;
                outDegree[v]++;
            }

        }
        int root = -1;
        for (int i =0;i<n;i++){
            if (outDegree[i] >2) return -1;
            if (inDegree[i] >1) return -1;
            if (inDegree[i] == 0){
                if (root != -1) return -1;
                root = i;
            }
        }
        return root;
    }
};
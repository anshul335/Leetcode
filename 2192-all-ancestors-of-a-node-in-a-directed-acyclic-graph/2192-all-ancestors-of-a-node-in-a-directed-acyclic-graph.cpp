class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        for (auto it : edges){
            adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
        }
        queue<int>q;
        for (int i =0;i<n;i++){
            if (inDegree[i] == 0) q.push(i);
        }

        vector<unordered_set<int>> arr (n);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (auto it : adj[node]){
                inDegree[it] -- ;
                arr[it].insert(node);
                for (auto last : arr[node]){
                    arr[it].insert(last);
                }
                if (inDegree[it] == 0) q.push(it);
            }
        }

        for (int i =0;i<n;i++){
            vector<int>curr ;
            for (auto it : arr[i]){
                curr.push_back(it);

            }
            sort(curr.begin(),curr.end());
            ans[i] = curr;
        }

        return ans ;
    }
};
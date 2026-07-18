class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>ans(n,-1);
        vector<vector<int>>adj(n);
        vector<int> indegree(n,0);
        for (int i =0;i<richer.size();i++){
            adj[richer[i][0]].push_back(richer[i][1]);
            indegree[richer[i][1]]++;
        }
        // for (int i =0;i<adj.size();i++){
        //     cout<<i<<"-> ";
        //     for (auto it :adj[i]){
        //         cout<<it<<" ";
        //     } 
        //     cout<<indegree[i];
        //     cout<<endl;
        // }
        
        queue<int>q;
        for (int i =0;i<n;i++){
            if (indegree[i]==0){
                ans[i] = i;
                q.push(i);
            }
        }
        while (!q.empty()){
            int top = q.front();
            q.pop();
            for (auto it : adj[top]){
                indegree[it] --;
                if (indegree[it] == 0) q.push(it);
                if (ans[it] == -1){
                    ans [it] = it;
                }
                if (quiet[ans[top]] < quiet[ans[it]])ans[it] = ans[top];
            }
        }

        return ans ;
    }
};
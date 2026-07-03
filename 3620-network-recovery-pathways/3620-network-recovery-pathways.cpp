class Solution {
public:
    bool check(int mini , vector<vector<pair<int,int>>>&adj,long long k,int n){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>dis(n,LLONG_MAX);
        dis[0] = 0;
        
        while(!pq.empty()){
            long long currCost = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            if (currCost > dis[currNode]) continue;
            for (auto it : adj[currNode]){
                int nextNode = it.first ;
                long long nextCost = currCost + it.second;
                if (it.second < mini) continue;
                if (nextCost > k) continue;
                if (dis[nextNode]>nextCost){
                    dis[nextNode] = nextCost ;
                    pq.push({nextCost,nextNode});
                }
            }
        } 
        return dis[n-1] != LLONG_MAX;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>>adj(n);
        long long low = LLONG_MAX;
        long long high = LLONG_MIN;
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            long long w = it[2];
            if (!online[u] || ! online[v]) continue;
            adj[u].push_back({v,w});
            low = min(low,w);
            high = max(high,w);
        }
        int ans = -1 ;
        while (low<=high){
            long long mid = low + (high-low)/2;
            if (check(mid,adj,k,n)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;

        
        
    }
};
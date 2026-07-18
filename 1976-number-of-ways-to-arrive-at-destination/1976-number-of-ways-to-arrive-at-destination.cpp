class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for (auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> way (n);
        vector<long long>totalTime(n,LLONG_MAX);
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>pq;
        pq.push({0,0});
        way[0] = 1;
        totalTime[0] = 0;
        while (!pq.empty()){
            long long currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (currTime> totalTime[node]) continue;
            for (auto it : adj[node]){
                if (currTime + it.second < totalTime[it.first]){
                    totalTime[it.first] = currTime + it.second;
                    way[it.first] = way[node];
                    pq.push({totalTime[it.first],it.first});
                }
                else  if (currTime + it.second == totalTime[it.first]){
                    
                    way[it.first] = (way[node]+way[it.first])%MOD;
                    
                }
            }
        }
        return way[n-1];
    }
};
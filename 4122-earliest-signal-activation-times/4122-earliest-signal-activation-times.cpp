class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<long long> ans (n, -1);
        // { cost , node}
        priority_queue<pair<long long , int> ,vector<pair<long long , int>>, greater<>>pq;
        vector<vector<pair<int,int>>> adjList(n);
        for (auto it : edges){
            adjList[it[0]].push_back({it[1], it[2]});
        }
        pq.push({0, 0});
        while (!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int currNode = it.second;
            long long currCost = it.first;
            requiredSignals[currNode]--;
            if(currNode != 0 && requiredSignals[currNode] >0) continue; 
            if (ans[currNode] != -1 ) continue;
            if(ans[currNode] == -1 ) ans[currNode] = currCost;
            for (auto nextNode : adjList[currNode]){
                int v = nextNode.first;
                long long cost = nextNode.second;
                long long nextCost = currCost  + cost;
                pq.push({nextCost, v});
            }
        }
        return ans;
    }
};
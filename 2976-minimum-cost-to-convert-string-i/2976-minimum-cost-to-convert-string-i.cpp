// class Solution {
// public:
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         vector<vector<int>> dist(26,vector<int>(26,INT_MAX));
//         for (int i=0;i<original.size();i++){
//             char org = original[i];
//             int c =cost[i];
//             char change = changed[i];
//             dist[org - 'a'][change - 'a'] = min(c,dist[org - 'a'][change - 'a']);
//         }
//         for (int via = 0 ;via<26;via ++ ){
//             for (int i=0;i<26;i++){
//                 for (int j =0;j<26;j++){  
//                     if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
//                 }
//             }
//         }
//         long long ans = 0;
//         for (int i =0;i<source.size();i++){
//             if (source[i] != target[i]){
//                 if (dist[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1;
//                 ans += dist[source[i] - 'a'][target[i] - 'a'];
//             }
//         }
//         return ans ;
//     }
// };
class Solution {
public:
    long long dikjstra (vector<vector<pair<int,int>>> &adj , char source, char target){
        int s  = source - 'a';
        int tar = target - 'a';
        vector<int> dis(26 , INT_MAX);
        dis[s] = 0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,s});
        while (!pq.empty()){
            int curr = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if (curr == tar) return cost;
            if (dis[curr] < cost) continue;
            for (auto it : adj[curr]){
                int nextCost = it.second + cost;
                if (dis[it.first] > nextCost){
                    dis[it.first] = nextCost;
                    pq.push({nextCost, it.first});
                }
            }
        }
        return dis[tar];
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        for (int i=0;i<original.size();i++){
            char org = original[i];
            int c =cost[i];
            char change = changed[i];
            adj[org - 'a'].push_back({change - 'a',c});
        }
        vector<vector<int>> alreadyCalc(26, vector<int>(26,INT_MAX));
        long long ans = 0;
        for (int i =0;i<source.size();i++){
            if (source[i] != target[i]){
                if (alreadyCalc[source[i]-'a'][target[i]-'a'] != INT_MAX){
                    ans += alreadyCalc[source[i]-'a'][target[i]-'a'];
                    continue;
                }
                long long curr = dikjstra(adj, source[i] , target[i]);
                if (curr == INT_MAX) return -1;
                ans += curr;
                alreadyCalc[source[i]-'a'][target[i]-'a'] = curr;
            }
        }
        return ans ;
    }
};
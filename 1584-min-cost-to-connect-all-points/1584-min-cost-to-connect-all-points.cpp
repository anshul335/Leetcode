class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{points[0][0],points[0][1]}});
        set<pair<int,int>>vis;
        while (!pq.empty()){
            int w = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (vis.find({x,y}) != vis.end()) continue;
            cost += w;
            vis.insert({x,y});
            for (int i =0;i<points.size();i++){
                int nx = points[i][0];
                int ny = points[i][1];
                int dis = abs(x-nx) + abs(y-ny);
                if (x != nx || y != ny){
                    if (vis.find({nx,ny}) == vis.end()){
                        pq.push({dis,{nx,ny}});
                    }
                }
            }
        }
        return cost;
    }
};
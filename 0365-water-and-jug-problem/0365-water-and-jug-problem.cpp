class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        unordered_set<int>st;
        queue<int>q;
        vector<int> vis (x+y+1,0);
        q.push(0);
        vis[0] = 1;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            if (node == target) return true;
            int nextNode = node + x;
            if (nextNode >= 0 && nextNode <= x+y && vis[nextNode] == 0){
                q.push(nextNode);
                vis[nextNode] = 1;
            }
            nextNode = node - x;
            if (nextNode >= 0 && nextNode <= x+y && vis[nextNode] == 0){
                q.push(nextNode);
                vis[nextNode] = 1;
            }
            nextNode = node +y;
            if (nextNode >= 0 && nextNode <= x+y && vis[nextNode] == 0){
                q.push(nextNode);
                vis[nextNode] = 1;
            }
            nextNode = node - y;
            if (nextNode >= 0 && nextNode <= x+y && vis[nextNode] == 0){
                q.push(nextNode);
                vis[nextNode] = 1;
            }
        }
        return false;
    }
};
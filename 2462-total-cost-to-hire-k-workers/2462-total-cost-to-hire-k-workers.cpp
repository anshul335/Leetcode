class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        long long ans = 0;
        priority_queue<int,vector<int>,greater<int>>start;
        priority_queue<int,vector<int>,greater<int>>end;
        int i =0;
        int j = costs.size()-1;
        for (int t =0;t<k;t++){
            while (start.size() < c && i <= j){
                start.push(costs[i]);
                i++;
            }
            while (end.size() < c && i <= j){
                end.push(costs[j]);
                j--;
            }
            if (start.empty()) {
                ans += end.top();
                end.pop();
            }
            else if (end.empty()){
                ans += start.top();
                start.pop();
            }
            else if (start.top() <= end.top()){
                ans += start.top();
                start.pop();
            }
            else {
                ans += end.top();
                end.pop();
            }
        }
        return ans ;

    }
};
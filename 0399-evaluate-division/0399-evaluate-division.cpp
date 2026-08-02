class Solution {
public:
    bool dfs(unordered_map<string , vector<pair<string, double>> > &adjList, double &currAns,
            unordered_map<string , int> &visited, string start , string end  ){
                if (adjList.find(start) == adjList.end() || 
                adjList.find(end) == adjList.end()) return false ;

                if (start == end) return true;

                bool temp = false ;
                visited[start] = 1;
                for (auto &it : adjList[start]) {
                    if (!visited[it.first]) {
                        currAns *= it.second;
                        if (dfs(adjList, currAns, visited, it.first, end))return true;
                        currAns /= it.second; 
                    }
                }
                return false; 

            }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , vector<pair<string, double>> > adjList ;
        int n = equations.size();
        for (int i =0;i<n;i++){
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        vector<double> ans;
        for (int i =0;i<queries.size();i++){
            double currAns = 1;
            unordered_map<string , int> visited;
            bool path = dfs(adjList, currAns, visited, queries[i][0], queries[i][1]);
            if (path) ans.push_back(currAns);
            else ans.push_back(-1);
        }
        return ans ;
    }
};
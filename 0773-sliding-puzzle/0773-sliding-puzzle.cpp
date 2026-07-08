class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>moves = {{1,3}, {0,2,4},{1,5},{0,4},{3,1,5},{2,4}};
        string curr = "";
        for (int i =0;i<2;i++){
            for (int j = 0;j<3;j++){
                curr += (board[i][j] + '0');
            }
        }
        set<string>visited ;
        queue<string>q;
        int ans  = 0;
        visited.insert(curr);
        q.push(curr);
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                string currNode = q.front();
                q.pop();
                if (currNode == "123450") return ans;
                for (int i =0;i<currNode.length();i++){
                    if (currNode[i] =='0'){
                        for (int ind =0;ind<moves[i].size();ind++){
                            swap(currNode[moves[i][ind]],currNode[i]);
                            if (visited.find(currNode) == visited.end()){
                                q.push(currNode);
                                visited.insert(currNode);
                            }
                            swap(currNode[moves[i][ind]],currNode[i]);
                        }
                    }
                }
            }
            ans ++;
        }
        return  -1;
    }
};
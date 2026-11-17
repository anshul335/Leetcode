class Solution {
public:
    int ans;
    void solve (int ind, int count ,int n ,  vector<vector<int>>& requests, vector<int> & countReq){
        int m = requests.size();
        if (ind >= m){
            bool flag = true;
            for (int i =0;i<n;i++){
                if (countReq[i] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans = max(ans, count);
            return ;
        }
        solve (ind+1, count , n, requests, countReq);
        vector<int> currRequest = requests[ind];

        countReq[currRequest[0]]--;
        countReq[currRequest[1]]++;
        solve(ind+1, count+1, n, requests, countReq);
        countReq[currRequest[0]]++;
        countReq[currRequest[1]]--;
        return ;

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        ans = 0;
        vector<int>countReq(n,0);
        solve (0, 0, n, requests, countReq);
        return ans ;
    }
};
class Solution {
public:
    int solve(vector<int> & nums, vector<bool>& visited, int ops, unordered_map<vector<bool> , int> &mpp){
        if (mpp.find(visited) != mpp.end()) return mpp[visited];
        int n = nums.size();
        int ans = 0;
        for (int i = 0;i<n-1;i++){
            if (visited[i] == true) continue;
            for (int j = i+1;j<n;j++){
                if (visited[j] == true) continue;
                visited[i] = true;
                visited[j] = true;

                int curr = ops * __gcd(nums[i], nums[j]);
                int remain = solve(nums, visited, ops+1, mpp);

                ans = max(ans, curr + remain);
                visited[i] = false;
                visited[j] = false;
            }
        }
        return mpp[visited] = ans;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        unordered_map<vector<bool> , int>  mpp;
        vector<bool> visited(n,false);
        return solve(nums, visited, 1, mpp);
    }
};
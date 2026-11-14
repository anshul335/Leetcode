class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mpp;
        int ans = 0;
        for (int num : time){
            int rem = num % 60;
            int req = 60 - rem;
            if (req == 60) req = 0;
            ans += mpp[req];
            mpp[rem]++;
        }
        return ans;
    }
};
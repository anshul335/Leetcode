class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int>sum(n+1,0);
        vector<long long>power(n+1,1);
        vector<long long>val(n+1,0);
        vector<long long>nonZero(n+1,0);
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i-1] * 10) % MOD;
        }
        for(int i = 0;i<n;i++){
            int x = s[i]-'0';
            if(x!=0){
                sum[i+1] = sum[i]+x;
                nonZero[i+1] = nonZero[i]+1;
                val[i+1] = (val[i]*10+x)%MOD;
            }
            else {
                sum[i+1] = sum[i];
                nonZero[i+1] = nonZero[i];
                val[i+1] = val[i];
            }
        }
        vector<int> ans;
        for(int i =0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int p = nonZero[r+1]-nonZero[l];
            long long left =  (val[l]*power[p] )%MOD;
            long long x = (val[r+1]-left + MOD)%MOD;
            long long s = sum[r+1]- sum[l];
            ans.push_back((int)x*s%MOD);
        }
        return ans;
    }
};
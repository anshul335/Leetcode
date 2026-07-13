class Solution {
public:
    unordered_map<int,int>memo;
    int power(int num){
        if (num == 1) return memo[num] = 0;
        if (memo.find(num) != memo.end()) return memo[num];
        if (num % 2 == 0 ) return memo[num] = 1 + power(num/2);
        return memo[num] = 1 + power(3 * num +1 );
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> ans;

        for (int i =lo ;i<=hi;i++){
            if (memo.find(i) != memo.end())ans.push_back({memo[i],i});
            else ans.push_back({power(i),i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};
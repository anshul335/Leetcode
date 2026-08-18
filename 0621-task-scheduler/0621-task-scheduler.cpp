class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        int count = 0;
        for(int i =0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
            count = max(count,freq[tasks[i]-'A']);

        }
        int ans = (count-1)*(n+1);
        for(auto e:freq){
            if(e==count)ans++;
        }
        return max((int)tasks.size(),ans);
    }
};
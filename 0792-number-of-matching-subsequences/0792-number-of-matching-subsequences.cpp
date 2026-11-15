class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charMapping(26);
        for (int i =0;i<s.length();i++){
            charMapping[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for (auto word:words){
            int lastChar = 0;
            bool flag = true;
            for (int i =0;i<word.size();i++){
                vector<int>& curr = charMapping[word[i]-'a'];
                auto lower = lower_bound(curr.begin(), curr.end(), lastChar) - curr.begin();
                if (lower < curr.size()){
                    lastChar = curr[lower]+1;
                }
                else flag = false;
            }
            if (flag) ans++;
        }
        return ans;
    }
};
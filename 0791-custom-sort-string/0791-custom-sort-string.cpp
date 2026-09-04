class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0);
        for (int i =0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        string ans = "";
        for (int i =0;i<order.length();i++){
            int curr = order[i] - 'a';
            if (freq[curr] != 0){
                while (freq[curr]>0){
                    ans += order[i];
                    freq[curr] -- ;
                }
            }
        }
        for (int i =0;i<26;i++){
            while (freq[i]>0){
                ans += (i+ 'a');
                freq[i] -- ;
            }
        }
        return ans ;
    }
};
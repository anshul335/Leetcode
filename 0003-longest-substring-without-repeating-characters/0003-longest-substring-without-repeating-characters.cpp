class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char,int> freq;
        int start = 0;
        for (int end = 0 ;end < s.length();end ++ ){
            freq[s[end]] ++ ;
            while (freq[s[end]]>1){
                freq[s[start]] -- ;
                start ++ ;
            }
            ans = max(ans , end - start +1);
        }
        return ans ;
    }
};
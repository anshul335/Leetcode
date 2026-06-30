class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mpp;
        int ans = 0;
        int left = 0;
        int right = 0;
        while(right<s.length()){
            mpp[s[right]]++;
            while(mpp['a']>0&&mpp['b']>0&&mpp['c']>0){
                ans+=(s.length()-right);
                mpp[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};
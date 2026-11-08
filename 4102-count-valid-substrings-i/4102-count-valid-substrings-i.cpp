class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int invalid = -1;
        for (int i =0;i<s.length();i++){
            if (i >=2 && s[i-2] == 'a' && s[i-1] == 'b'  && s[i] == 'c'){
                invalid = i-2;
            }
            
            ans += (i- invalid);
            

        }
        return ans;
    }
};
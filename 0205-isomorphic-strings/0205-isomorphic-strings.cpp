class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp;
        unordered_map<char,char> mpp2;
        for (int i =0;i<s.length();i++){
            if (mpp.find(s[i]) != mpp.end()){
                if (t[i] != mpp[s[i]]) return false;
            }
            if (mpp2.find(t[i]) != mpp2.end()){
                if (s[i] != mpp2[t[i]]) return false;
            }
            mpp[s[i]] = t[i];
            mpp2[t[i]] = s[i];
        }
        return true;
    }
};
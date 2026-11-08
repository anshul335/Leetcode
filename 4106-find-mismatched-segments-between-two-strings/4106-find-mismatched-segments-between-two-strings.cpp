class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int i =0;
        while (i < s1.length()){
            if (s1[i] == s2[i]) {
                i++;
                continue;
            }
            int startIndex = i;
            while (i < s1.length() && s1[i] != s2[i]){
                i++;
            }
            ans.push_back({s1.substr(startIndex, i - startIndex), s2.substr(startIndex, i - startIndex)});
        }


        return ans;
    }
};
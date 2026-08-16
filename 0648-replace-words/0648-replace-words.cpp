class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        string ans = "";
        unordered_map<string,int> mpp;
        for (int i=0;i<dictionary.size();i++){
            mpp[dictionary[i]]++;
        }
        string curr = "";
        int n = s.length();
        for (int i=0;i<s.length();i++){
            if (s[i] == ' '){
                curr = "";
                ans += ' ';
                continue;
            }
            curr += s[i];
            ans += s[i];
            if (mpp.find(curr) != mpp.end()){
                while (i<n && s[i] != ' ') i++;
                
                 i--;
            }


        }
        if(ans.back() == ' ')ans.pop_back();
        return ans ;
    }
};
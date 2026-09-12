class Solution {
private:
    void solve(string digit,string output,int i,vector<string>&ans,string value[]){
        if(i>=digit.length()) {
            ans.push_back(output);
            return;
        }
        int n=digit[i]-'0';
        string s=value[n];
        for(int j=0;j<s.length();j++){
            output.push_back(s[j]);
            solve(digit,output,i+1,ans,value);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string value[10]={"",    "",    "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        string output;
        int i=0;
        if(digits.length()==0) return ans;
        solve(digits,output,i,ans,value);
        return ans;
    }
};
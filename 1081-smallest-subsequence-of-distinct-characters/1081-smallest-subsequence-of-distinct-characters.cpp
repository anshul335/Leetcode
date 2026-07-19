class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]=i;
        }
        stack<char>st;
        unordered_set<char> visited;
        for(int i=0;i<s.length();i++){
            if(visited.find(s[i])!=visited.end()){
                continue;

            }
            while(!st.empty()&&s[i]<st.top()&&i<mpp[st.top()]){
                visited.erase(st.top());
                st.pop();
                
            }
            visited.insert(s[i]);
            st.push(s[i]);
            
        }
        string ans="";
        while(!st.empty()){
            ans= st.top()+ans;
            st.pop();
        }
        return ans ;
    }
};
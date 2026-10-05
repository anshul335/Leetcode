class Solution {
public:
    int scoreOfParentheses(string s) {
        int val=0;
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(val);
                val=0;
            }
            else {
                val= st.top()+max(2*val,1);
                st.pop();
            }
        }
        return val;
    }
};
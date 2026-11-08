class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<vector<int>> st;
        for (int i =0;i<types.size();i++){
            int type = types[i];
            int c = colors[i];
            if (!st.empty() && st.top()[0] == type && st.top()[1] == c){
                st.top()[2]++;
            }
            else {
                st.push({type,c,1});
            }
            if (st.top()[2] == groupSize[type]){
                st.pop();
            }
        }
        return st.empty();

    }
};
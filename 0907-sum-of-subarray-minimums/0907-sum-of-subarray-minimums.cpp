class Solution {
public:
    vector<int>nextSmallerEle(vector<int> & arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n) ;
        for (int i = n-1;i>=0;i--){
            int curr = arr[i];
            while (!st.empty() && arr[st.top()] >=  arr[i]){
                st.pop();
            }
            if (st.empty()) ans [i] = n;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans ;

    }
    
    vector<int>prevSmallerEle(vector<int> & arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n) ;
        for (int i = 0;i<n;i++){
            int curr = arr[i];
            while (!st.empty() && arr[st.top()] >  arr[i]){
                st.pop();
            }
            if (st.empty()) ans [i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans ;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmallerEle (arr);
        vector<int> pse = prevSmallerEle(arr);
        int ans = 0;
        const int mod = 1e9+7;
        int n = arr.size();
        for (int i =0;i<n;i++){
            int left = pse[i] - i;
            int right = i - nse[i];
            int curr = (1LL * arr[i] * (left *right)) % mod ;
            ans = (ans + curr) % mod;
        }
        return ans ;
    }
};
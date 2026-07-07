
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.length();
        vector<bool> isEqual(n,false);
        for (int i =0;i<n;i++){
            if (s1[i] == s2[i]) isEqual[i] = true;
        }
        
        queue<pair<string,int>> q;
        for (int i =0;i<n;i++){
            if (isEqual[i] == false){
                q.push({s1,i});
            }
        }
        int ans = 0;
        unordered_map<string,int>mpp;
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                string curr = q.front().first;
                int ind = q.front().second;
                q.pop();
                if (curr == s2) return ans ;
                while (ind < n && curr[ind]== s2[ind]) ind++;
                for (int i = ind +1 ;i<n;i++){
                    if ( curr [i] == s2[ind] && curr[i] != s2[i]){
                        swap(curr[i],curr[ind]);
                        if (mpp.find(curr) == mpp.end()){
                            q.push({curr,ind+1});
                            mpp[curr] = 1;
                        }
                        swap(curr[i],curr[ind]);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
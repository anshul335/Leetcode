class Solution {
public:
    bool isRepeated(string & s, string curr, int k){
        int count =0;
        int i =0;
        int j =0;
        while (j< s.length()){
            if (s[j] == curr[i]){
                i++;
                if (i == curr.length()){
                    count++;
                    i = 0;
                    if (count == k) return true;
                }
            }
            j++;
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans = "";

        queue<string>q;
        q.push("");
        while (!q.empty()){
            string curr = q.front();
            q.pop();
            for (char ch = 'a' ;ch<='z';ch++){
                string next = curr + ch;
                if (isRepeated(s,next,k)){
                    ans = next ;
                    q.push(next);
                }
            }
        }

        return ans ;
    }
};
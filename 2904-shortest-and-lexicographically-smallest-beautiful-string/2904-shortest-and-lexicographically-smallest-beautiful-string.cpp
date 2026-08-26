class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i =0;
        int j = 0;
        int count = 0;
        string ans = "";
        while (j<s.size()){
            if (s[j] == '1'){
                count++;
            }
            while (count>k){
                if (s[i] == '1') count--;
                i++;
            }

            if (count == k){
                while (i < j && s[i] == '0'){
                    i++;
                }
                string curr = s.substr(i,j - i +1);
                if (ans == "" || ans.size() > curr.size() || (ans.size() == curr.size() && curr< ans)){
                    ans = curr;
                }
            }
            j++;

        }
        return ans ;
    }
};
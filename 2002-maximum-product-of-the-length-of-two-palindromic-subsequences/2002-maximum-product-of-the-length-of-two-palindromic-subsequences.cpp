class Solution {
public:
    int ans = 0;
    bool isPalindrome(string a){
        int i =0;
        int j = a.length() - 1;
        while (i<j){
            if (a[i] != a[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve (string & s, string &a, string &b,int ind){
        if (ind >= s.length()){
            if (isPalindrome(a) && isPalindrome(b)) ans = max(ans, (int)a.length() * (int)b.length());
            return ;
        }

        a.push_back(s[ind]);
        solve (s,a,b,ind+1);
        a.pop_back();

        b.push_back(s[ind]);
        solve (s,a,b,ind+1);
        b.pop_back();
        solve (s,a,b,ind+1);


    }
    int maxProduct(string s) {
        string a = "";
        string b = "";
        solve (s,a,b,0);
        return ans;
    }
};
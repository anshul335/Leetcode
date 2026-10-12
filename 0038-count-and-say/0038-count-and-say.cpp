class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ans = "1";
        for (int i =1;i<n;i++){
            int currVal = (ans[0] - '0');
            int count = 1;
            string nextAns = "";
            for (int j = 1;j<ans.length();j++){
                if (currVal == (ans[j]- '0')){
                    count++;
                }
                else {
                    nextAns += count + '0';
                    nextAns += currVal + '0';
                    currVal = (ans[j] - '0');
                    count = 1;
                }

            }
            nextAns += count + '0';
            nextAns += currVal + '0';
            ans = nextAns;
        }
        return ans ;

    }
};
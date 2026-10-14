class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num ) return "";
        int nineCount = sum / 9;
        int remain = sum%9;
        string ans = "";
        for (int i =0;i<nineCount ;i++)ans += '9';
        if (ans.size() < num)ans += (remain + '0');
        while (ans.size() < num){
            ans += '0';
        }
        return ans ;
    }
};
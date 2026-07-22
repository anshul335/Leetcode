class Solution {
public:
    bool isNumber(string s) {
        int expo = 0;
        int decimal = 0;
        int numberBeforeExpo = 0;
        int numberAfterExpo = 0;
        for (int i =0;i<s.length();i++){
           if (s[i] == '.') {
                if (expo) return false;
                if (++decimal > 1) return false;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (++expo > 1) return false;
                if (numberBeforeExpo == 0) return false;
            }
            else if (isdigit(s[i])) {
                if (expo)numberAfterExpo++;
                else numberBeforeExpo++;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (i != 0 && s[i-1] != 'e' && s[i-1] != 'E')return false;
            }
            else {
                return false;
            }
        }
        if (numberBeforeExpo == 0) return false;
        if (expo && numberAfterExpo == 0) return false;
        return true;
    }
};
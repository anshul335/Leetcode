class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int index = num1.find('+');
        int r1 = stoi(num1.substr(0,index));
        int i1 = stoi(num1.substr(index+1,num1.size() - index -2));
         index = num2.find('+');
        int r2 = stoi(num2.substr(0,index));
        int i2 = stoi(num2.substr(index+1,num2.size() - index -2));
        int ansr = (r1 * r2) - (i1 * i2);
        int ansi = (r1*i2) + (r2*i1);
        string ans = to_string(ansr) + "+"+to_string(ansi)+"i";
        return ans ;
    }
};
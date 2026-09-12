class Solution {
public:
    int strStr(string hay, string n) {
        for(int i=0;i<hay.length();i++){
            if(hay.substr(i,n.length())==n){
                return i;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        int neg = (x < 0);
        x=abs(x);

        long long ans = 0;
        while (x >0){
            int r = x %10;
            if (ans > INT_MAX / 10 ) {
                return 0; 
            }
            x = x/10;
            ans = ans *10 + r;
        }
        if (neg == 1) return -1 * ans ;
        return ans;

    }
};
class Solution {
public:
    int dp[101][10001];
    // Ye bhi TLE de diyaaa mujhe to ques hi smjh nhi aya aree Question tho easy sa h mereko just ye check karna h ki mimum kiten iteraytion lagenge ki mereko floor pata chal jaye ki kispar egg tutega tho mene kya kiya ki isme 2 case h agar egg tut gaya tho me upper wale check nhi karung kyuki unpe tho tutega hi isliye mene ek recusuion call kiya jisme k-1 pass iya and i -1 pass kar diya 
    // agar egg nhi tuta tho matlab wo floor ya tho current h ya upper wali h tho mene k , n-i pass kar diya agcbbha aisme binary search lagata hu kyuki ese tho n2 ja raha h code 
    int recursion(int k,int n){
        if (n==0) return n;
        if (n==1) return n;// ynh
        if (k==1) return n;
        if (dp[k][n]!=-1) return dp[k][n];
        int ans = INT_MAX;
        int low = 1;
        int high = n;
        while (low<=high){
            int mid = low + (high-low)/2;
            int left = recursion(k,n-mid);
            int right = recursion(k-1,mid-1);
            int curr = 1+ max(right ,left);
            ans = min(ans,curr);
            if (left>right) low = mid+1;
            else high = mid-1;
        }
        return dp[k][n] = ans;
    }
      int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return recursion(k,n);    
    }
};
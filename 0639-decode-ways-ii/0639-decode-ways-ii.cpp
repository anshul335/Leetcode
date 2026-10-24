class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[100005];

    int solve(string& s, int ind) {
        int n = s.length();

        if (ind >= n)
            return 1;

        if (dp[ind] != -1)
            return dp[ind];

        long long ans = 0;
        if (s[ind] == '*') {
            ans += 9LL * solve(s, ind + 1);
        }
        else if (s[ind] != '0') {
            ans += solve(s, ind + 1);
        }
        if (ind + 1 < n) {
            if (s[ind] == '*' && s[ind + 1] == '*') {
                ans += 15LL * solve(s, ind + 2);
            }
            else if (s[ind] == '*') {
                if (s[ind + 1] >= '0' && s[ind + 1] <= '6') {
                    ans += 2LL * solve(s, ind + 2);
                }
                else {
                    ans += solve(s, ind + 2);
                }
            }
            else if (s[ind + 1] == '*') {
                if (s[ind] == '1') {
                    ans += 9LL * solve(s, ind + 2);
                }
                else if (s[ind] == '2') {
                    ans += 6LL * solve(s, ind + 2);
                }
            }
            else {
                int curr = (s[ind] - '0') * 10 + (s[ind + 1] - '0');

                if (curr >= 10 && curr <= 26) {
                    ans += solve(s, ind + 2);
                }
            }
        }

        return dp[ind] = ans % MOD;
    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};
class Solution {
public:
    const int mod = 1e9 + 7;
    typedef vector<vector<int>> Matrix;
    Matrix matrixExpo(Matrix base , int expo){
        if (expo == 0){
            Matrix I(26,vector<int>(26,0));
            for (int i =0;i<26;i++){
               
                    I[i][i] = 1;
                
            }
            return I;
        }

        Matrix half = matrixExpo(base ,expo/2);
        Matrix ans = matrixMul(half , half);
        if (expo%2==1){
            ans = matrixMul(ans, base);
        }
        return ans ;
    }
    Matrix matrixMul(Matrix A, Matrix B){
        Matrix C ( 26 , vector<int>(26,0));
        for (int i =0;i<26;i++){
            for (int j =0;j<26;j++){
                for (int k =0;k<26;k++){
                    C[i][k] = (C[i][k] + (1LL*A[i][j]*B[j][k])%mod) % mod;
                }
            }
        }
        return C;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix T(26,vector<int>(26,0));
        for (int i=0;i<26;i++){
            for (int j = 1;j<= nums[i];j++){
                T[(i+j)%26][i]++;
            }
        }
        Matrix tn = matrixExpo(T,t);
        vector<int> freq(26, 0);

        for (char &ch : s) {
            freq[ch - 'a']++;
        }
        vector<int> finalFreq (26,0);
        for (int i =0;i<26;i++){
            for (int j =0;j<26;j++){
                finalFreq[i] = (finalFreq[i] + (1LL*freq[j] * tn[i][j])%mod)%mod;
            }
        }
        int ans = 0;
        for (int i =0;i<26;i++){
            ans = (ans  + finalFreq[i])%mod;
        }
        return ans;

    }
};
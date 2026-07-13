class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for (int i =1;i<=9;i++){
            int curr = i;
            for (int j = i+1;j<=9;j++){
                curr = curr *10 + j;
                if (curr >= low && curr <= high) ans.push_back(curr);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>yearWisePops(2051,0);
        for (int i =0;i<logs.size();i++){
            int start = logs[i][0];
            int end = logs[i][1]-1;
            for (int j =start;j<=end;j++) yearWisePops[j]++;
        }
        int year = 0;
        int maxi =0;
        for (int i =0;i<2051;i++){
            if (maxi < yearWisePops[i]){
                maxi = yearWisePops[i];
                year = i;
            }
        }
        return year;
    }
};
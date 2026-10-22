class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>yearWisePops(2051,0);
        for (int i =0;i<logs.size();i++){
            int start = logs[i][0];
            int end = logs[i][1];
            yearWisePops[start]++;
            yearWisePops[end]--;
        }
        int year = 0;
        int maxi =0;
        int count = 0;
        for (int i =0;i<2051;i++){
            count+= yearWisePops[i];
            if (maxi < count){
                maxi = count;
                year = i;
            }
        }
        return year;
    }
};
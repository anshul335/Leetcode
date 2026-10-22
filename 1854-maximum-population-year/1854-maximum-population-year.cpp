class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>yearWisePops;
        for (int i =0;i<logs.size();i++){
            int start = logs[i][0];
            int end = logs[i][1];
            yearWisePops.push_back({start, 1});
            yearWisePops.push_back({end , -1});
        }
        sort(yearWisePops.begin(), yearWisePops.end());
        int year = 0;
        int maxi =0;
        int count = 0;
        for (int i =0;i<yearWisePops.size();i++){
            count+= yearWisePops[i].second;
            if (maxi < count){
                maxi = count;
                year = yearWisePops[i].first;
            }
        }
        return year;
    }
};
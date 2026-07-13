class Solution {
public:
    int solve(vector<string>& garbage, vector<int>& travel,char ch){
        int pieces = 0;
        int last = -1;

        for (int i = 0; i < garbage.size(); i++) {
            for (char c : garbage[i]) {
                if (c == ch) {
                    pieces++;
                    last = i;
                }
            }
        }

        if (last == -1) return 0;

        int time = pieces;
        for (int i = 0; i < last; i++)
            time += travel[i];

        return time;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = solve(garbage , travel, 'G');
        ans += solve(garbage , travel, 'P');
        ans += solve(garbage , travel, 'M');
        return ans ;
    }
};
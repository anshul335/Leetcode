class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& arr, int k) {
        sort(arr.begin(), arr.end(), [&](auto const & a, auto const & b) {
            return a[k] > b[k];
        });
        return arr;
    }
};
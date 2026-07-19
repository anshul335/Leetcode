class Solution {
public:
    vector<vector<int>> findingSum(vector<int> arr) {
        int n = arr.size();
        vector<vector<int>> ans(n + 1);
        for (int i = 0; i < 1LL << n; i++) {
            int sum = 0;
            int size = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    sum += arr[j];
                    size++;
                }
            }
            ans[size].push_back(sum);
        }
        return ans;
    }
    bool splitArraySameAverage(vector<int>& arr) {
        int n = arr.size();
        int n1 = n / 2;
        int n2 = n - n1;
        int totalSum = accumulate(arr.begin(), arr.end(), 0LL);
        vector<vector<int>> first =findingSum(vector<int>(arr.begin(), arr.begin() + n1));
        vector<vector<int>> second =findingSum(vector<int>(arr.begin() + n1, arr.end()));
        for (int i = 0; i < second.size(); i++)
            sort(second[i].begin(), second[i].end());

        for (int i = 0; i< first.size(); i++) {
            for (auto it : first[i]) {
                for (int j = 0; j < second.size(); j++) {
                    if (i + j == 0 || i + j == n)
                        continue;

                    // (x+y)/ (i+j) == (total - (x+y))/(n-(i+j)) now by this
                    int k = i + j;
                    if ((1LL * totalSum * k) % n)
                        continue;

                    int target = 1LL * totalSum * k / n;
                    int need = target - it;

                    if (binary_search(second[j].begin(), second[j].end(), need))
                        return true;
                }
            }
        }
        return false;
    }
};
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    void buildSegmentTree(int i, int l, int r, vector<int>& tree, const vector<int>& arr) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, tree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, tree, arr);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }

    int querySegmentTree(int start, int end, int i, int l, int r, const vector<int>& tree) {
        if (start > end || l > end || r < start) {
            return INT_MIN;
        }
        if (l >= start && r <= end) {
            return tree[i];
        }
        int mid = l + (r - l) / 2;
        return max(
            querySegmentTree(start, end, 2 * i + 1, l, mid, tree),
            querySegmentTree(start, end, 2 * i + 2, mid + 1, r, tree)
        );
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int totalOnes = count(s.begin(), s.end(), '1');
        
        vector<int> start, end, size;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int st = i;
                while (i < n && s[i] == '0') i++;
                start.push_back(st);
                end.push_back(i - 1);
                size.push_back(i - st);
            } else {
                i++;
            }
        }

        int m = start.size();
        if (m < 2) {
            return vector<int>(queries.size(), totalOnes);
        }
        vector<int> pairSum(m - 1);
        for (int k = 0; k < m - 1; k++) {
            pairSum[k] = size[k] + size[k + 1];
        }
        vector<int> tree(4 * (m - 1));
        buildSegmentTree(0, 0, m - 2, tree, pairSum);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int left = q[0];
            int right = q[1];
            int low = lower_bound(end.begin(), end.end(), left) - end.begin();
            int high = upper_bound(start.begin(), start.end(), right) - start.begin() - 1;

            int maxTradeGain = 0;

            if (low < high) {
                int firstLen = end[low] - max(start[low], left) + 1;
                int lastLen = min(end[high], right) - start[high] + 1;

                if (high - low == 1) {
                    maxTradeGain = firstLen + lastLen;
                } else {
                    int pair1 = firstLen + size[low + 1];
                    int pair2 = lastLen + size[high - 1];
                    
                    int internalRMQ = INT_MIN;
                    if (low + 1 <= high - 2) {
                        internalRMQ = querySegmentTree(low + 1, high - 2, 0, 0, m - 2, tree);
                    }

                    maxTradeGain = max({pair1, pair2, internalRMQ});
                }
            }

            ans.push_back(totalOnes + maxTradeGain);
        }

        return ans;
    }
};
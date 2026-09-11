class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int last = heights[0];

        for (int i = 1; i < heights.size(); i++) {
            int curr = heights[i];
            int required = curr - last;

            if (required <= 0) {
                last = curr;
            }
            else {
                last = curr;
                bricks -= required;
                pq.push(required);

                if (bricks < 0) {
                    if (ladders == 0) {
                        return i-1;
                    }

                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
            }
        }

        return heights.size() - 1;
    }
};
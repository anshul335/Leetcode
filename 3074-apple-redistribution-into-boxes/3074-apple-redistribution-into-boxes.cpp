class Solution {
public:
    int minimumBoxes(vector<int>& apples, vector<int>& capacity) {
        int sum = accumulate(apples.begin(), apples.end(), 0LL);
        sort(capacity.begin(), capacity.end());
        int ans = 0;
        for (int i = capacity.size()-1;i>=0;i--){
            sum -=capacity[i];
            ans++;
            if (sum <=0) return ans ;
        }
        return ans ;

    }
};
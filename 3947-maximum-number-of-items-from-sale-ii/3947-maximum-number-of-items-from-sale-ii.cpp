class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        long long leastCost = INT_MAX;
        int maxN = items.size() + 1;
        vector<int> mpp(maxN, 0);
        vector<int> minCostOfEachFactor(1e5, INT_MAX);
        for (auto it : items){
            leastCost = min(1LL*leastCost,1LL*it[1]);
            minCostOfEachFactor[it[0]] = min(minCostOfEachFactor[it[0]], it[1]);
            mpp[it[0]]++;
        }

        vector<int> count(maxN, 0);
        for (int i = 1;i<maxN;i++){
            if (mpp[i] != 0){
                int currCount = 0;
                for (int j = i;j<maxN;j+=i){
                    currCount += mpp[j];
                }
                count[i] = (currCount-1);
            }
        }
        map<long long,long long> mpp2;

        for (auto it : items){
            if (count[it[0]]>0 && it[1] < 2LL * leastCost ){
                mpp2[it[1]] += count[it[0]];
            }
        }

        int ans = 0;
        long long amount = budget;
        for (auto it : mpp2){
            long long buyingCapcaityOfThisItem = amount/it.first;
            long long take = min(buyingCapcaityOfThisItem, it.second);
            ans += (take * 2);
            amount -= (take * it.first);
        }
        ans += (amount/leastCost );
        return ans ;


    }
};
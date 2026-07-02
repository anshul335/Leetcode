/*
kese krogey dp se? Kar sakte h dp se bhi me deque se sochne ka try kr raha tha thik h
ok aa gaya samaj deque se tho aa gaya kaise karna h as such hard nhi h acha Ha m soch lun ek baar thodi der aur
dekho apne ko isme 2 chije dekhi h ek ki Ok Socho 
btana kya krna h
Aapko deque se maximum subarray elemnt nukalana aata h ?shyd 
Agar wo nhi aata hoga tho muskil h thoda samjhana but me try karta hu 
dekho apne ko isme 2 chij ka dhan rakhna h ek tho index - last idex <= k hona chiaye and ek apne ko maximum chaiye 
tho apan deque use karenege pair me jisme first me naswer and second index rakh lenge shuru me ans ko INT_Min kar do kyuki dekho -1 bhi answer h kisi ka aslo apne ko -ve walo ko dequee me push karna ko koi matalab nhi h kyuki wo at the end kam hi karenge apne answer ko 
Now apan kya krenge ki start se har element par jayenge then usne deueue ka first eleemt plus kar denge  abb first hi kyu kar rahe h kyuki apna deque jo bana rahe h wo decreasing deque banyenge apan thik h tho apan phle usme apna deuquw ka first element add kiya fir ans ke max le liya then apan kya karenge ki deque se piche se check karenge ki konsa element chota h jo chota hua usko pop kar denge simply then apne ko ye bhi check karna h ki jo first elemnt h uska index curr index se -k wali jo condtion h ya nhi agar wo satisy nhio ho rahi tho usko pop kar denge bass ye hi algo 


Samaj Aaya  ha Tho code likho fir 
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>>dq;
        int maxi=INT_MIN;
        for (int i =0;i<n;i++){
            int curr = nums[i];
            if (!dq.empty()) curr += dq.front().first;
            maxi = max(curr,maxi);
            // me karu ?
            //mujhe smjh nhi aa rha bilkul bhi mene phle hi bola tha aapko deque wala aata hoga tho hi aayega warna bhot hi muskil h ek baar striver ki video dekh lo deque ki? ek maximum subarray sum kareke h tho okk sliding window maximum karke h video h 
            while (!dq.empty()&& dq.back().first <= curr){
                dq.pop_back();
            }
            if (curr>0){
                dq.push_back({curr,i});
            }
            if (!dq.empty() && dq.front().second == i- k ) dq.pop_front();
        }
        return maxi;
    }
};
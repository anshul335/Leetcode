/*
phle pdhke approach discuss krengey fir code krenegy thik h  ye next greater element ka question h kya ?
stack ka 
Ha stack ka tho h hi but stack me concept h na next gretaer element achaa 
next greater ka kese hoga beech m chota aagya vo to count hoga hi nhi jese person 0 person 3 ko nhi dekh payega 1 2 ko dekh payega next greater se phle bs
Nahi samaj aaya aap kya bol rahe ho 
pta nhi
Dekho me ye bol raha tha ki apan last se start karenge tho last se bada tho ki h hi nhi tho uska answer ho gaya 0 thm hum second last eemnt ko dekheng tho wo tho abhi tak sabsebada h tho wo last elemt ko dekh paayega and usko apan stack me store kar lenge then apan index 3 par dekheneg tho usse bada wala element just next wala means index 4 hi h tho wo sirf usko dekh paayega then apan index 2 part aaye apan ne next greater element se nikaal liya kiya ki index 4 hi next gretaer element usse means ki in dono ke bich ke saare elements chote h unse tho apan dono index ko 
minus kar denge and index 2 ko bhi stack me daal denge then apan aaye index 1 par fir dekha ki index 2 hi h next gretaer element tho dono ke index ko minus kara and answer me daal diya then apan aaye index 0 par yaha par mera logic kam nhi kar raaha kyuki answer hona choaute the 4 but 3 hi h 
kyuki index 2 wale ne index 3 ko chupa liya 
aesa krengey ki last wale index ko chodke sbko 1 se initalise kr dengey then agar jb tk first elemnt chota hoga tb tk pop krengey aur usko khudko stack m daal dengey jitne elemnt pop hongey wo ans m + ho jayega??yhi bola tumne? Ha thik h  karo implement abb 
*/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>ans(n,0);
        // Kyu hi kar rahe ho push last wale element ke liye tho kuch pop hoga hi nhi tho apane ko add karne ki 0 karene ki bhi jarrurat nhi h and wo automatically 0 ho jatga kyuk ch pop hi nhi ho raha 
        for (int  i = n-1;i>=0;i--){
            int count = 0;
            while(!st.empty()&&st.top()< heights[i]){
                count++;
                st.pop();
            }
            // Ok dekho abhi pata h kya ho raha h ye apan nikal liya ki wo bich ke kitne element dekh sakta h ha but isme ek problem h ki wo last wala agar bacha hua h like isme next greater uska count nhi ho rha?
            // Ha wo hi problem h ki o count nhi ho raha but apne ko karna padega bt agar apan sab me +1 aesa kr sktey h na ki ge thaagr usse bda present h to +1 kr dengey usko po pop nhi krrobelm eh knyuki esa kiya tho aggar waal lo purea stacky hi empty ho gaya and koi next gretaer element mila hi nahi tho ye sunoooo aesa kr dengey ki agr stck m ussey bda h to usme +1 krengey otherwise nhi aur pop nhi krengey usko Ha 
            ans[i] = count;
            if (!st.empty()) ans[i] ++;
            
            
            st.push(heights[i]);
        }
            
        return ans;
    }
};
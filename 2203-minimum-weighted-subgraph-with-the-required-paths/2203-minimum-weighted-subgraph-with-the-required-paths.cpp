class Solution {
public:
    // Isko apan ese kar sakte h ki apan har k=node ka har nodde se de=istance nikaal le gain floyd se hi then apan kya kare ki LCA find kar le fir ans ho jayega sorc1 se LCA ki distance + src2 se LCa ki distance + LCA ki final dest se distance and iska minimum ye answer ho jayega samjhe ??mujhe y lgta h shyd cubic nhi chlega yhan
    // Oh haa n2 hi nhi chlega hn aki value 1e5 h dijsktra hi lgani h
    // -1 wala to wo case h jb y dono alg componenets k part hon wo tho gar answer INT_MAX hoga tho auto maticallye -1 kar denge ye probhlaem nhi h ha
    //like kuch aesa ki src1 ka dest se src2 ka dest se aur agr y ek dusre k path m nhi a rhe hn to src ka src 2 se dist bhi add kr dengey
    // ha nhi aa rahe wala case tho bhot easy h main h ki aa rahe h tho ka karenge kyuki usme cost ko ek hi baar add karni h , nhi aane wale me tho direct laga do 
    // me bolta hu 3 baar dijsktra lagate h 
    // First src1 se tho apne ko saare node ki distance pata lag jayegi then src2 tho saare node ki dis pata chal jayegi 
    // Areee apn esa karenge ki dest se nikal leneg har node ki fir add kare lenge lide src1 to that node +  src2 of that node + dest to that node  haaaa yhi kr skte hnn graph directed gven h  tho piche kaise jaynge 
    // Abb ye problem h node nikalni ?common wali nahi jab dest se sabki distance nikalenge tho piche traverse karna padega na and graph tho directed h tho piche kaise jaynege 
    // m y kh rhi hunn common node kese nikalogyy aapko ye samaj aaya ki me teeno ki distance nikal lunga the
    // Then me loop chalaunga 0 to n and ans ko rakhunga int Max for me loop ke andar likhung ki src1se i ki distance kya h  + sirc2 se i ki distance kya h  + dis se i ki distance kya h tho and sbka min lete jaunga 
    // mujhe y smjh aya h kii agr inme common hua path to whi case krna h mainly to usme 
    // suppose node N se common h path dono m to weight hoga src 1 to N +src to N + N to dest and node N kesi niklgei? ha ye hi karna h abb problem ye hi h ki dist se n kaise niklega kyuki graph directed h 
    //inka sath sath path print bhi krlen to fir dekhlennn ussey pta chl jayega 2 dono cases ka ki common h to bhi coomon node nikl jayegi nhi h to wo bhi pta chl jayega print ka kya sense yaha par ??? print mtlb store krlen dono ka ki src 1 se dest tk phuachte wkt konsi konsi node thiiiii wo to kr skte hn na dijsktra lgate lgate fir comapre kr lenegy
    // There is a chance ki wo node na mile like agar me jab siingke single kar raha hu dono ka src se dist tak  tho there is a chnaces ki hum LCA se jaye hi na  hme minimum weight chiye to phle min path p jayegngey fir lca dhundengey shyd    
    // djdktra kabhi lca nhi dhundh sakta 
    
///areee dijsktra min path to deta h na aur hm y dekhnegy ki mi pathhh m lca h ya nhi agr nhi h to   but waha chnaces h ki dijstra jo paath de usme LCA ho hi nhi ye hi tho me bol raha hu kabse ha to fir jo an hoga vo src1 to dest+src to dest +src1 to src 2 ho ga shyd Nhi ese nhi hota ye galat h ese tho galat answer aayega 
//srry fir ans hoga min(src1 to dest, src2 to dest)+src1 to src2 or sorc1 jane ka koi rasta h nhi hua thooo src 2 se aesa sirf tbhi hoga jb y connected componet k part nhi hongeyaap galat soch rahe hoo 
// are y btao y cheez to sirf tbhi possible jb y alg ag comp k part hon wrna to hmesha hoga 
// rasta kisis na kisis th  Achaa karo implment aapko pata chla jayega ki aap galat ho 
// to reason btao na phlee kyu glt h 
// y chodo y btaoooo aree mereko test case generte nhi ho raha but me sich paa raha hu ki aap galat ho iska ans krow ki 2 comp k part hone k alwa bhi y possible h ki koi path ho na phauchne ka?ha ya na paath ja sakta h but wo unnecarry path ho sakta h bhott 
//mujhe nhi aa rha smjh kuch bhi kya kr rhe ho tum bolo kuc gpt bol raha h we are almost there jo mene aapko bataya tha kya ki src1 se saare node ki distnacde and src2 se ssaare node ki distance nikalo and dist se saare node ki dist nikla0 fir loop laga ke  + wala jo mene bol tha 
/*
    src1 -> i
    +
    src2 -> i
    +
    i -> dest
*/

//mujhe nhi aya smjh kya bol rhe ho
   // achaa me karta hu 
    
//sunoo agr koi coomon node nhi h to wo common node destination hi h ?
// Ha esa ho sakta h let me do it with my logic 
    //suno phleee y btao common node nhi h uske liye kya krre ho tum mere case me common node ya tho last wala hoga ya biche me kahi hoga warna answer -1 hoga 
    void solve (vector<long long>&dis,int node,vector<vector<pair<int,int>>>&adj){
        priority_queue<pair<long long, int>, vector<pair<long long,int>> , greater<pair<long long ,int>>> pq;
        pq.push({0,node});
        dis[node] = 0;
        while(!pq.empty()){
            int currNode = pq.top().second  ;
            long long currDist = pq.top().first;
            pq.pop();
            if (currDist > dis[currNode]) continue;
            for (auto it : adj[currNode]){
                int nextNode  = it.first; // Yaha error aa raha h kya h error run karke dekh lo 
                long long nextCost = currDist + it.second; 
                if (nextCost < dis[nextNode]){
                    pq.push({nextCost , nextNode});
                    dis[nextNode] = nextCost;
                }
            }
            
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<pair<int,int>>>reverseAdj(n);// y dest ki liye h? Ha 
        
        for (auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            reverseAdj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<long long>src1Dist(n,LLONG_MAX);
        vector<long long>src2Dist(n,LLONG_MAX);
        vector<long long>destDist(n,LLONG_MAX);
        solve (src1Dist,src1,adj);
        solve (src2Dist,src2,adj);
        solve (destDist,dest,reverseAdj);
        
        long long ans = LLONG_MAX;
        
        for (int i = 0;i<n;i++){
            if (src1Dist[i]==LLONG_MAX || src2Dist[i]==LLONG_MAX || destDist[i]==LLONG_MAX) continue;
            ans = min(ans , src1Dist[i]+src2Dist[i]+destDist[i]);
        }
        
        if (ans == LLONG_MAX) return -1;
        return ans ;
    }
};
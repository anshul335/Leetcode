/*
 Kya socha kaise karoge 
 soch hi rhi thi aesa to nhi kr skte na ki hr erase k baad connect kren aur fir check kren vo to tle aa jayega Ha sayad TLE tho aayega dsu ka to 1 hota h na?union and find ka? log n 
 alpha(n) y hota h na aur y almost 1 hota h Achaa 
 Aree Apne ko fall wala nikalna h tho abne ko sayad path compression nhi karn aisme fir tho jo bhi node me hataunga uske child jitne bhi honge wo saaare hat saayenge and wo hi anwer honge sayad esa hi kuch 
 Ya ese kar sakte h like phle cut kare fir dekhe like reverse me cut krke fir hr baar connect kren fir unka parent check kren aese?
 Pata nhi yaar kya karna h 
 Thoda sochnee do 
 haaa
 
 Ok Thoda samja me aaya 
 dekho apan hata ne lag gaye tho bhot proble ho jayegi tho me soch raha tha ki let just say apan jo hata ne wale h unko add hi na kare 
 
 
 suno aesa krte hn shyd ki dsu m connect kr skte hn but hta to nhi skte
 to sari brick remove krke fir connected componenet bna len root se aur fir piche se connect krte chlennn Ha me bhi yahi bol raha tha 
 mereko bhi click ho gaya tha ye 
 So dsu ka code likh deta hu me  HELLOO ???haaa Aap main code likh do approch steps m likho phle
 
 dekho phle apan ek temp grud banayenge jisme phle hi apan ho hatane wale h unko add kar denge 0 se then hum jo bache hue block h unko ek dsu me add karenge tho usse last wale ka an swer aa jayega  Bolo ?? kya bol rahe the sari brick remove krke jitne bhi connected componenets hn sb bnane pdengey kyunki jb nyi brick add krengey to usse connected bricks bhinn oneected ho jayengiha wo check kare lenge jab add karenge tho Aaya samaj ?? 
 
 
 yhi krna h na
 phle ek matrix bnani h jisme sari bricks remove ho chuki hn 
 then uske sare ones k connected componenet bnane hn
 then brick add krni h aur fir. dekhna h vo add hone k baad roof se connect h ya nhi 
 agr h to uske sare jo componenets k andr h vo bhi hongeyy fir ans ho jayega tota-ab wale not total last wala - abb wala haaa
 yhi krna h na Ha thik h m niche main code likhti hun ha thik h 
*/

class Solution {
public:
    vector<int>parent;
    vector<int>size ;
    int find (int n){
        if (parent[n]==n) return n;
        return parent[n] = find(parent[n]);
    }
    void Union(int x,int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x!=parent_y){
            if (size[parent_x]>size[parent_y]) {
                parent[parent_y] = parent_x;
                size[parent_x] += size[parent_y]; 
            }
            else {
                parent[parent_x] = parent_y;
                size[parent_y] += size[parent_x]; 
            }
        }
    }//suno parent m*n size ka h na tum isko 2d matrix hi bna do nahi id se hi karenge m*n ok+1 iss size ka bana lo kyuki ek top node bhi use kar lenge jisse saare first row ke node connected honge ofcourse jo one h 
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>temp=grid;
        for(int i=0;i<hits.size();++i){
            int u=hits[i][0];
            int v=hits[i][1];
            temp[u][v]=0;
        }
        parent.resize(m*n+1,0);
        size.resize(m*n+1,1);
        for(int i =0;i<=m*n ;i++) parent[i] = i;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(temp[i][j]==1){
                    int ind = i*n + j ;
                    if (i==0){
                        Union(ind,m*n);
                    }
                    if (i+1< m && temp[i+1][j]==1){
                        Union(ind, (i+1)*n + j);
                    }
                    if (j+1< n && temp[i][j+1]==1){
                        Union(ind, (i)*n + (j+1));
                    }
                }
            }
        }
       vector<int>ans (hits.size());
       //y nhi hoga hme to unstable nikalni h na to wo hongey jo 1 h aur unka parent top nhi h ...hena? Mereko samaj nhi aa raha aap kya bol rahe ho //phle aap kar lo aapke hisaab se then me kar dunga ok
       
       
      //y thik h shyd/////helllo??? Chala ?are pura thodi h m puch rhi hun y shi h mujhe nhi pata ek baar aap kar lo fir me aaram se dekhuga ok 
      // kya hua ? pta nhiii me karta hu 
       for(int i=hits.size()-1;i>=0;i--){
        int u=hits[i][0];
        int v=hits[i][1];
        int ind1=u*n+v;
        if (grid[u][v]==0) {
            ans[i] = 0 ; 
            continue ;
        }
        int last = size[find(m*n)];
        temp[u][v] = 1;
        if (u==0) Union(ind1, n*m);
       
        vector<vector<int>>direction = {{-1,0},{1,0},{0,1},{0,-1}};
        for (int d = 0;d<4;d++){
            int nextU = u + direction[d][0];
            int nextV = v + direction[d][1];
            if (nextU<0|| nextV<0 || nextU>= m || nextV >=n || temp[nextU][nextV]==0) continue;
            Union(ind1, nextU * n + nextV);
        }
        
        int currSize = size[find(n*m)];
        if (find(ind1) == find(n*m)){
            ans[i] = 0;
            ans[i] = max(ans[i],currSize-last-1);
        }
        else ans[i] = 0;
        
    
        
        //ab y kese nikalun ki konsi konsi brick stable ho gyi Wo size badh jayegi ka authomatically 
        //wo tho aap dekh lo na jo top node the apna jo mene banaya h m*n wala tho uski jo size h unte node stable h abhi current ans kitna h 
       }
       return ans;
        
    }
};
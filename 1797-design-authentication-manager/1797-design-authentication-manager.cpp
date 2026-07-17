class AuthenticationManager {
public:
    int timeToLive;
    map<string,int>mpp;
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mpp[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if (mpp.find(tokenId)!=mpp.end()){
            if (mpp[tokenId] > currentTime)mpp[tokenId] = currentTime + timeToLive;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto it : mpp){
            if (it.second>currentTime) ans++;
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
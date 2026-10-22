class MyCalendarTwo {
public:
    map<int,int> mpp;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
        int currCount = 0;
        int maxCount = 0;
        for (auto it : mpp){
            currCount+=it.second;
            maxCount = max(maxCount , currCount);
        }
        if (maxCount>=3){
            mpp[startTime]--;
            mpp[endTime]++;
            return false;
        }
        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
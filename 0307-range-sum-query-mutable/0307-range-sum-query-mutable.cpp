class NumArray {
public:
    vector<int> arr ;
    int n ;
    vector<int>blocks;
    int blockSize ;
    NumArray(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        blockSize = ceil(sqrt(n));
        blocks.assign(blockSize, 0);
        for(int i =0;i<n;i++){
            blocks[i/blockSize] += nums[i];
        }

    }
    
    void update(int index, int val) {
        int last = arr[index];
        int blockIndex = index/blockSize;
        blocks[blockIndex] -= arr[index];
        arr[index] = val;
        blocks[blockIndex] += val;
    }
    
    int sumRange(int left, int right) {
        int startBlock = left /blockSize ;
        int endBlock = right / blockSize;
        if (startBlock == endBlock){
            int sum = 0;
            for (int i =left ;i<= right;i++){
                sum+= arr[i];
            }
            return sum;
        }
        int sum = 0 ;

        int endofStartBlock = (startBlock +1) *blockSize -1;
        for (int i =left ;i<= endofStartBlock;i++){
            sum += arr[i];
        }
        for (int i =startBlock + 1; i <= endBlock-1 ;i++){
            sum += blocks[i];
        }
        int startOfEndBlock = endBlock * blockSize;
        for (int i =startOfEndBlock ;i<= right ;i++){
            sum += arr[i];
        }
        return sum ;


    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
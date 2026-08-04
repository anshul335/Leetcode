class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mpp = new HashMap<>();
        int n = nums.length;
        for (int i =0;i<n;i++){
            int curr = target - nums[i];
            if (mpp.containsKey(curr)){
                return new int[]{mpp.get(curr), i};
            }
            mpp.put(nums[i],i);
        }
        return new int[]{};
    }
}
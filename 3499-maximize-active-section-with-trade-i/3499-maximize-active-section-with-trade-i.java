class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int one = 0;
        int n = s.length();
        for (char ch : s.toCharArray()) if (ch == '1') one++;
        List<Integer > block = new ArrayList<>();
        int i =0;
        while (i <n){
            int start = i;
            while (i< n && s.charAt(i) == s.charAt(start)) i++;
            if (s.charAt(start) == '0') block.add(i-start);
        }
        if (block.size() ==1) return one;
        int maxi = 0;
        for (int j =0;j<block.size() - 1;j++){
            maxi = Math.max(maxi, block.get(j) + block.get(j+1));
        }
        return one + maxi;
        
    }
}
class Solution {
public:
    bool hasDuplicate(string& temp,string curr){
        int arr[26] = {0};
        for (char & ch:temp){
            arr[ch-'a']++;
            if (arr[ch-'a']>1) return true;
        }
        for (char & ch: curr){
            arr[ch-'a']++;
            if (arr[ch-'a']>1) return true;
        }
        return false;
    }
    int solve (vector<string> & arr, int ind , string temp , int n ){
        if (ind >= n) return temp.length();
        int take = 0;
        int notTake = 0;
        if (hasDuplicate(temp, arr[ind])){
            notTake = solve(arr, ind+1, temp , n);
        }
        else {
            take = solve(arr, ind+1, temp+arr[ind], n);
            notTake = solve(arr, ind+1, temp, n);
        }
        return max(take , notTake);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        int i =0;
        return solve(arr, i, temp, n);
    }
};
class Solution {
public:
    bool isVowel(char c) {
        return string("AEIOUaeiou").find(c) != string::npos;
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(), vowels.end());
        int j =0;
        for (int i =0;i<s.length();i++){
            if (isVowel(s[i])) s[i] = vowels[j++];
        }
        return s;
    }
};
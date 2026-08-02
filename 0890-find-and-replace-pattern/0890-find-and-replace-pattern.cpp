class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for (auto &word : words) {
            unordered_map<char, char> mp1, mp2;
            bool ok = true;

            for (int i = 0; i < pattern.size(); i++) {
                char p = pattern[i];
                char w = word[i];

                if (mp1.count(p) && mp1[p] != w) {
                    ok = false;
                    break;
                }

                if (mp2.count(w) && mp2[w] != p) {
                    ok = false;
                    break;
                }

                mp1[p] = w;
                mp2[w] = p;
            }

            if (ok) ans.push_back(word);
        }

        return ans;
    }
};
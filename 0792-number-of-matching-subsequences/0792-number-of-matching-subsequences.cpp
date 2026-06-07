class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        int count = 0;
        for(string &word : words) {
            int prev = -1;
            bool found = true;
            for(char ch : word) {
                if(mp.find(ch) == mp.end()) {
                    found = false;
                    break;
                }
                auto &pos = mp[ch];
                auto it = upper_bound(pos.begin(), pos.end(), prev);
                if(it == pos.end()) {
                    found = false;
                    break;
                }
                prev = *it;
            }
            if(found)
                count++;
        }

        return count;
    }
};
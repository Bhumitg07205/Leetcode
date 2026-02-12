class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            int distinct = 0;
            int maxfreq = 0;
            for (int j = i; j < n; j++) {
                if (freq[s[j]] == 0) {
                    distinct++;
                }
                freq[s[j]]++;
                maxfreq = max(maxfreq, freq[s[j]]);
                if (maxfreq * distinct == j - i + 1) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};

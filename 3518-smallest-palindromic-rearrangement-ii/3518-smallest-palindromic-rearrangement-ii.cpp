#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MAX = 1000001;

    string smallestPalindrome(string s, long long k) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;

        if (!isPalindromePossible(count)) return "";

        vector<int> halfCount;
        char midLetter;
        tie(halfCount, midLetter) = getHalfCountAndMidLetter(count);

        long long totalPerm = calculateTotalPermutations(halfCount);
        if (k > totalPerm) return "";

        vector<char> leftHalf = generateLeftHalf(halfCount, k);
        string left(leftHalf.begin(), leftHalf.end());
        string right(left.rbegin(), left.rend());

        return left + (midLetter == '\0' ? "" : string(1, midLetter)) + right;
    }

private:
    bool isPalindromePossible(unordered_map<char, int>& count) {
        int oddCount = 0;
        for (auto& [c, freq] : count) {
            if (freq % 2 == 1) oddCount++;
        }
        return oddCount <= 1;
    }

    pair<vector<int>, char> getHalfCountAndMidLetter(unordered_map<char, int>& count) {
        vector<int> halfCount(26, 0);
        char midLetter = '\0';
        for (auto& [c, freq] : count) {
            halfCount[c - 'a'] = freq / 2;
            if (freq % 2 == 1) midLetter = c;
        }
        return {halfCount, midLetter};
    }

    long long calculateTotalPermutations(vector<int>& halfCount) {
        return countArrangements(halfCount);
    }

    vector<char> generateLeftHalf(vector<int>& halfCount, long long k) {
        int halfLen = accumulate(halfCount.begin(), halfCount.end(), 0);
        vector<char> left;
        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCount[i] == 0) continue;
                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);
                if (arrangements >= k) {
                    left.push_back('a' + i);
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }
        return left;
    }

    long long countArrangements(vector<int>& count) {
        int total = accumulate(count.begin(), count.end(), 0);
        long long res = 1;
        for (int freq : count) {
            res *= nCk(total, freq);
            if (res >= MAX) return MAX;
            total -= freq;
        }
        return res;
    }

    long long nCk(int n, int k) {
        long long res = 1;
        for (int i = 1; i <= min(k, n - k); i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX) return MAX;
        }
        return res;
    }
};

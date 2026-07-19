class Solution {
public:
    bool isVowel(char c){
        vector<char> v = {'a','e','i','o','u'};
        if( find(v.begin(), v.end(), c) != v.end())return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        int count = 0;
        int maxi = 0;

        while(j < n){
            if(j - i + 1 < k){
                if(isVowel(s[j])) count++;
                j++;
            }
            else if(j - i + 1 == k){
                if(isVowel(s[j])) count++;

                maxi = max(maxi, count);

                if(isVowel(s[i])) count--;

                i++;
                j++;
            }
        }

        return maxi;
    }
};
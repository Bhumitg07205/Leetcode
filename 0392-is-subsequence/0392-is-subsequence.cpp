class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        while(n>=0 && m>=0){
            if(s[n]==t[m]){
                n--;
                m--;
            }
            else m--;
        }
        if(n==-1)return true;
        return false;
    }   

};
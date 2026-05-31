class Solution {
    private: 
    vector<vector<int>>memo;
    int countSub(string s,string t, int m,int n){
        if((m==-1 && n==-1) || n==-1)return 1;
        if(m==-1)return 0;
        if(memo[m][n]!=-1)return memo[m][n];
        if(s[m]==t[n]){
            memo[m][n]=countSub(s,t,m-1,n-1)+countSub(s,t,m-1,n);
            return memo[m][n];
        }
        memo[m][n]=countSub(s,t,m-1,n);
        return memo[m][n];
    }
public:
    int numDistinct(string s, string t) {
        int m=s.length()-1;
        int n=t.length()-1;
        memo.assign(m+1,vector<int>(n+1,-1));
        return countSub(s,t,m,n);

    }
};
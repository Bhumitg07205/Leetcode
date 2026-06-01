class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(string &s:strs){
            int z=0;
            int o=0;
            for(char c:s){
                if(c=='0')z++;
                else o++;
            }
            for(int i=m;i>=z;--i){
                for(int j=n;j>=o;--j){
                    int include=dp[i-z][j-o]+1;
                    int exclude=dp[i][j];
                    dp[i][j]=max(include,exclude);
                }
            }
        }
        return dp[m][n];
    }
};
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i==j)dp[i][i]=piles[i];
                if(i<j){
                    int pick_left=piles[i]-dp[i+1][j];
                    int pick_right=piles[j]-dp[i][j-1];
                    dp[i][j]=max(pick_left,pick_right);
                }
            }
        }
        return dp[0][n-1]>0;

    }
};
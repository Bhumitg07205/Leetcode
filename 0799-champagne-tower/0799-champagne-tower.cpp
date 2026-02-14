class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n = 100;
       vector<vector<double>> dp(query_row+1, vector<double>(query_row+1, 0.0));
vector<vector<double>> overflow(query_row+1, vector<double>(query_row+1, 0.0));
        
        dp[0][0] = poured;
        if (dp[0][0] > 1.0) {
            overflow[0][0] = dp[0][0] - 1.0;
            dp[0][0] = 1.0;
        }
        
        for (int i = 1; i <query_row+1; i++) {
            for (int j = 0; j <= i; j++) {
                double incoming = 0.0;
                
                if (j == 0) {
                    incoming = overflow[i-1][0] / 2.0;
                } else if (j == i) {
                    incoming = overflow[i-1][i-1] / 2.0;
                } else {
                    incoming = overflow[i-1][j-1] / 2.0 + overflow[i-1][j] / 2.0;
                }
                
                dp[i][j] = incoming;
                if (dp[i][j] > 1.0) {
                    overflow[i][j] = dp[i][j] - 1.0;
                    dp[i][j] = 1.0;
                }
            }
        }
        
        return min(1.0, dp[query_row][query_glass]);
    }
};
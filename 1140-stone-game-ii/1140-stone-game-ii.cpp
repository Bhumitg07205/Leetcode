class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        function<int(int,int)> dfs = [&](int i, int M) {
            if (i >= n) return 0;
            if (dp[i][M] != 0) return dp[i][M];
            if (i + 2 * M >= n) return suffix[i];
            
            int best = 0;
            for (int x = 1; x <= 2 * M; ++x) {
                best = max(best, suffix[i] - dfs(i + x, max(M, x)));
            }
            return dp[i][M] = best;
        };
        
        return dfs(0, 1);
    }
};

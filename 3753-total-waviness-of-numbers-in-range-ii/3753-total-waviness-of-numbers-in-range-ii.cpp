class Solution {
private:
    pair<long long, long long> memo[20][11][11][2][2];
    string S;

    pair<long long, long long> dfs(int idx, int prev1, int prev2, bool tight, bool is_zero) {
        if (idx == S.length()) {
            return {0, 1}; 
        }
        if (memo[idx][prev1][prev2][tight][is_zero].first != -1) {
            return memo[idx][prev1][prev2][tight][is_zero];
        }

        int limit = tight ? S[idx] - '0' : 9;
        long long total_wave = 0;
        long long total_count = 0;

        for (int d = 0; d <= limit; d++) {
            bool next_tight = tight && (d == limit);
            bool next_zero = is_zero && (d == 0);
            int next_prev1 = next_zero ? 10 : d;
            int next_prev2 = next_zero ? 10 : prev1;

            auto child = dfs(idx + 1, next_prev1, next_prev2, next_tight, next_zero);
            
            long long current_wave = 0;
            
            if (!is_zero && prev1 != 10 && prev2 != 10) {
                if ((prev1 > prev2 && prev1 > d) || (prev1 < prev2 && prev1 < d)) {
                    current_wave = 1;
                }
            }
            total_wave += child.first + (current_wave * child.second);
            total_count += child.second;
        }

        return memo[idx][prev1][prev2][tight][is_zero] = {total_wave, total_count};
    }

    long long getWaviness(long long num) {
        if (num < 100) return 0; 
        
        S = to_string(num);
        for(int i = 0; i < 20; ++i) {
            for(int j = 0; j < 11; ++j) {
                for(int k = 0; k < 11; ++k) {
                    for(int t = 0; t < 2; ++t) {
                        for(int z = 0; z < 2; ++z) {
                            memo[i][j][k][t][z] = {-1, -1};
                        }
                    }
                }
            }
        }
        return dfs(0, 10, 10, true, true).first;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return getWaviness(num2) - getWaviness(num1 - 1);
    }
};
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        
        vector<long long> pow10(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }
        
        vector<long long> S(n + 1, 0);
        vector<long long> C(n + 1, 0);
        vector<long long> P(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            int d = s[i] - '0';
            S[i + 1] = S[i] + d;
            if(d != 0) {
                C[i + 1] = C[i] + 1;
                P[i + 1] = (P[i] * 10 + d) % MOD;
            } else {
                C[i + 1] = C[i];
                P[i + 1] = P[i];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for(auto& q : queries) {
            int l = q[0], r = q[1];
            
            long long cnt = C[r + 1] - C[l];
            // Modulo arithmetic: add MOD before final modulo to prevent negative numbers
            long long val = (P[r + 1] - (P[l] * pow10[cnt]) % MOD + MOD) % MOD;
            long long sum = S[r + 1] - S[l];
            
            long long res = (val * (sum % MOD)) % MOD;
            ans.push_back(res);
        }
        
        return ans;
    }
};
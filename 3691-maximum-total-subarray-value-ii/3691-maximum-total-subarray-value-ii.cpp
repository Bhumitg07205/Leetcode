class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return 0;
        int max_log = log2(n) + 1;
        vector<vector<int>> max_st(n, vector<int>(max_log));
        vector<vector<int>> min_st(n, vector<int>(max_log));
        vector<int> lg(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }
        for (int i = 0; i < n; i++) {
            max_st[i][0] = nums[i];
            min_st[i][0] = nums[i];
        }
        
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                max_st[i][j] = max(max_st[i][j - 1], max_st[i + (1 << (j - 1))][j - 1]);
                min_st[i][j] = min(min_st[i][j - 1], min_st[i + (1 << (j - 1))][j - 1]);
            }
        }
        auto get_val = [&](int l, int r) {
            int j = lg[r - l + 1];
            int mx = max(max_st[l][j], max_st[r - (1 << j) + 1][j]);
            int mn = min(min_st[l][j], min_st[r - (1 << j) + 1][j]);
            return (long long)mx - mn;
        };
        
        priority_queue<pair<long long, pair<int, int>>> pq;
        
        for (int l = 0; l < n; l++) {
            pq.push({get_val(l, n - 1), {l, n - 1}});
        }
        
        long long ans = 0;
        
        while (k > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            long long val = top.first;
            int l = top.second.first;
            int r = top.second.second;
            
            ans += val;
            k--;
            
            if (r > l) {
                pq.push({get_val(l, r - 1), {l, r - 1}});
            }
        }
        
        return ans;
    }
};
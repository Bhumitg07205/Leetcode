class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        vector<long long> ans;
        for (int q : queries) {
            int idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long operations = 0;
            if (idx > 0) {
                long long sum = prefix[idx - 1];
                operations += 1LL * q * idx - sum;
            }
            
            if (idx < n) {
                long long sum = prefix[n - 1] - (idx > 0 ? prefix[idx - 1] : 0);
                operations += sum - 1LL * q * (n - idx);
            }

            ans.push_back(operations);
        }

        return ans;
    }
};
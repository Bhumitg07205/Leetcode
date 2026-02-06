class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int maxKeep = 1;  
        for(int i = 0; i < n; i++) {
            long long maxAllowed = (long long)nums[i] * k;
            int right = upper_bound(nums.begin(), nums.end(), maxAllowed) - nums.begin();
            
            
            maxKeep = max(maxKeep, right - i);
        }
        
        return n - maxKeep;
    }
};

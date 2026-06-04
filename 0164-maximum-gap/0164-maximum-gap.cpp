class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int mn = nums[0], mx = nums[0];
        for (int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }
        if (mn == mx) return 0;
        int gap = ceil((mx - mn) / (double)(nums.size() - 1));
        int bucketSize = (mx - mn) / gap + 1;
        vector<pair<int, int>> buckets(bucketSize, {INT_MAX, INT_MIN});
        for (int num : nums) {
            int bucketIndex = (num - mn) / gap;
            buckets[bucketIndex].first = min(buckets[bucketIndex].first, num);
            buckets[bucketIndex].second = max(buckets[bucketIndex].second, num);
        }
        int maxGap = 0;
        int prevMax = mn;
        
        for (const auto& bucket : buckets) {
            if (bucket.first == INT_MAX) continue;
            maxGap = max(maxGap, bucket.first - prevMax);
            prevMax = bucket.second;
        }
        
        return maxGap;
    }
};
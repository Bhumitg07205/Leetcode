class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        int maxLength = 0;
      
        int left = 0;
      
        for (int right = 0; right < nums.size(); ++right) {
            frequencyMap[nums[right]]++;
            while (frequencyMap[nums[right]] > k) {
                frequencyMap[nums[left]]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
      
        return maxLength;
    }
};

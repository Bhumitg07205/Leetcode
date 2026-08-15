class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total_xor = 0;
        bool all_zeros = true;
        
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                all_zeros = false;
            }
        }
        
        if (all_zeros) {
            return 0;
        }
        
        if (total_xor != 0) {
            return n;
        }
        
        return n - 1;
    }
};
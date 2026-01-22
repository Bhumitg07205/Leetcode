class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        
        // Keep looping until array is sorted
        while (!isSorted(nums)) {
            // Find pair with minimum sum
            int minSum = nums[0] + nums[1];
            int minIndex = 0;
            
            for (int i = 1; i < nums.size() - 1; i++) {
                int currentSum = nums[i] + nums[i + 1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    minIndex = i;
                }
            }
            
            // Replace pair with their sum
            nums[minIndex] = minSum;
            nums.erase(nums.begin() + minIndex + 1);
            count++;
        }
        
        return count;
    }
    
private:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
};

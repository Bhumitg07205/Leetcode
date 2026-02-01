class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int result=nums[0];
        nums[0]=INT_MAX;
        sort(nums.begin(),nums.end());
        result+=nums[0]+nums[1];
        return result;
    }
};
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max=0;
        for(int i=0;i<nums.size()/2;i++){
            int n=nums[i]+nums[nums.size()-i-1];
            if(max<n){
                max=n;
            }
        }
        return max;
    }
};

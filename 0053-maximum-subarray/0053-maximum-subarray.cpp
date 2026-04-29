class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        if(n==0)return 0;
        int maxi=nums[0];
        dp[0]=nums[0];
        if(n==1)return nums[0];
        for(int i=1;i<n;i++){
                dp[i]=max(nums[i],dp[i-1]+nums[i]);
                maxi=max(maxi,dp[i]);
            
        }
        return maxi;
    }
};
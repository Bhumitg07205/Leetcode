class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int count=0;
        int maxi=INT_MIN;
        while(j<n){
            if(nums[j]!=0){
                count++;
                j++;
            }else{
                i=j;
                j++;
                maxi=max(count,maxi);
                count=0;
            }
            
            maxi=max(count,maxi);
        }
        return maxi;
    }
};
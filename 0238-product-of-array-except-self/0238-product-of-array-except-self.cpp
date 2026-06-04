class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return {};
        vector<int>output(n,1);
        int left_prod=1;
        for(int i=0;i<n;i++){
            output[i]=left_prod;
            left_prod*=nums[i];
        }
        int right_prod=1;
        for(int i=n-1;i>=0;i--){
            output[i]*=right_prod;
            right_prod*=nums[i];
        }
        return output;
    }
};
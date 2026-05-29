class Solution {

public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int a:nums){
            mini=min(mini,getsum(a));
        }
        return mini;
    }
    private:
    int getsum(int a){
        int sum=0;
        while(a>0){
            sum+=a%10;
            a/=10;
        }
        return sum;
    }
};
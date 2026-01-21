class Solution {
public:
    int solve(int i){
        int d=1;
        int res=-1;
        while((d&i)!=0){
            res=i-d;
            d<<=1;
        }
        return res;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> output;
        for(int &i:nums){
            output.push_back(solve(i));
        }
        return output;
        
    }
};
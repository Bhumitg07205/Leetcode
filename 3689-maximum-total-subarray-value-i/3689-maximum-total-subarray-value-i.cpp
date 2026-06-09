class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxim=INT_MIN;
        long long minim=INT_MAX;
        for(auto &c:nums){
            maxim=max(maxim,(long long)c);
            minim=min(minim,(long long)c);
        }
        return (maxim-minim)*k;
    }
};
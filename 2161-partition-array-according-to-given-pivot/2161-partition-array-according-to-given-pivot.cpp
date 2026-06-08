class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less_than;
        vector<int>equal_to;
        vector<int>greater;
        for (int c:nums){
        if(c<pivot)less_than.push_back(c);
        else if(c==pivot)equal_to.push_back(c);
        else greater.push_back(c);
    }
    less_than.insert(less_than.end(),equal_to.begin(),equal_to.end());
    less_than.insert(less_than.end(),greater.begin(),greater.end());
    return less_than;
    }
};
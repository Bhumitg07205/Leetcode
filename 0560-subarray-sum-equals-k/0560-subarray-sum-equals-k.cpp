class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> prefix_sums;
        int count = 0;
        int curr_sum = 0;
        prefix_sums[0] = 1;

    for (int i = 0; i < arr.size(); i++) {
        curr_sum += arr[i];

        if (prefix_sums.find(curr_sum - k) != prefix_sums.end()) {
            count += prefix_sums[curr_sum - k];
        }
        prefix_sums[curr_sum]++;
    }

    return count;
    }
};
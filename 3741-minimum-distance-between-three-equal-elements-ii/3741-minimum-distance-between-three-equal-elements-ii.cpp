#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if (nums.size() < 3) {
            return -1;
        }
        unordered_map<int, vector<int>> indicesMap;
        for (int i = 0; i < nums.size(); ++i) {
            indicesMap[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        for (auto& pair : indicesMap) {
            const vector<int>& indices = pair.second;
            if (indices.size() >= 3) {
                for (int i = 0; i < indices.size() - 2; ++i) {
                    int first = indices[i];
                    int third = indices[i + 2];
                    
                    int current_dist = 2 * (third - first);
                    min_dist = min(min_dist, current_dist);
                }
            }
        }
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};
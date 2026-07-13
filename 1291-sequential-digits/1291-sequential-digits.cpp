#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        string sample = "123456789";
        vector<int> result;
        int low_len = to_string(low).length();
        int high_len = to_string(high).length();
        for (int length = low_len; length <= high_len; ++length) {
            for (int i = 0; i <= 9 - length; ++i) {
                string sub = sample.substr(i, length);
                int num = std::stoi(sub);
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};
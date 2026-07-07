class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long digit_sum = 0;
        long long factor = 1;
        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                digit_sum += d;
                x = x + d * factor;
                factor *= 10; 
            }
            n /= 10;
        }
        
        return x * digit_sum;
    }
};
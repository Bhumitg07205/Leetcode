class Solution {
public:
    void fwht(vector<long long>& a) {
        int n = a.size();
        for (int step = 1; step < n; step <<= 1) {
            for (int i = 0; i < n; i += step << 1) {
                for (int j = 0; j < step; j++) {
                    long long u = a[i + j], v = a[i + j + step];
                    a[i + j] = u + v;
                    a[i + j + step] = u - v;
                }
            }
        }
    }
    int uniqueXorTriplets(vector<int>& nums) {
        int size = 1;
        while (size <= 1500) size <<= 1; 
        size <<= 1;
        vector<long long> poly(size, 0);
        for (int x : nums) poly[x] = 1;
        fwht(poly);
        for (auto &x : poly) x = x * x * x; 
        fwht(poly);
        int ans = 0;
        for (auto x : poly) if (x != 0) ans++;
        return ans;
    }
};

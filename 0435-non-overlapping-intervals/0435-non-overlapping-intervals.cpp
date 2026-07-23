class Solution {
public:
    static bool second(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),second);
        int removals = 0;
        int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last) {
                removals++;
            } else {
                last = intervals[i][1];
            }
        }
        return removals;
    }
};




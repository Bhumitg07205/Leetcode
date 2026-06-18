class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=30*((minutes/60.0)+(hour%12));
        double y=6*minutes;
        return min((360-abs(y-x)),abs(y-x));
    }
};
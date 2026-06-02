class Solution {
public:
    int earliestFinishTime(vector<int>& landStart, vector<int>& landDuration, 
                          vector<int>& waterStart, vector<int>& waterDuration) {
        
        auto calc = [&](const vector<int>& start1, const vector<int>& dur1,
                       const vector<int>& start2, const vector<int>& dur2) {
            
            int minEnd = INT_MAX;
            for (int i = 0; i < start1.size(); i++) {
                minEnd = min(minEnd, start1[i] + dur1[i]); 
            }
            int result = INT_MAX;
            for (int i = 0; i < start2.size(); i++) {
                int startTime2 = max(minEnd, start2[i]);
                int finishTime = startTime2 + dur2[i];
                result = min(result, finishTime);  
            }
            return result;
        };
        int landFirst = calc(landStart, landDuration, waterStart, waterDuration); 
        int waterFirst = calc(waterStart, waterDuration, landStart, landDuration);
        return min(landFirst, waterFirst);
    }
};
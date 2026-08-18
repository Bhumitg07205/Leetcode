class Solution {
    struct compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> heap(points.begin(), points.begin() + k);
        
        for (int i = k; i < points.size(); i++) {
            auto point = points[i];
            
            int dist_point = point[0] * point[0] + point[1] * point[1];
            auto top_point = heap.top();
            int dist_top = top_point[0] * top_point[0] + top_point[1] * top_point[1];
            
            if (dist_point < dist_top) {
                heap.pop();
                heap.push(point);
            }
        }
        
        vector<vector<int>> result;
        while (!heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }
        
        return result;
    }
};
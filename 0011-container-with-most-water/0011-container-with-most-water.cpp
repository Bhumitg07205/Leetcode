class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int maximum=INT_MIN;
        int right=height.size()-1;
        while(left<right){
        int width=right-left;
        int hieght=min(height[left],height[right]);
        int area= width*hieght;
        maximum=max(maximum,area);
        if(height[left]>height[right]){
            right--;
        }else{left++;}
        }
        return maximum;
        
    }
};
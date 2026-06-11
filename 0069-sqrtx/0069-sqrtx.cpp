class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        float ans=0;
        while(s<=e){
            long long mid=(s+e)/2;
            if(mid*mid==x){
                return mid;
            }else if(mid*mid<x){
                ans=mid;
                s=mid+1;
            }else e=mid-1;
            
        }
        return ans;

    }
};
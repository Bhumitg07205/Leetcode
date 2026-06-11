class Solution {
public:
    bool isPerfectSquare(int num) {
        int s=0;
        int e=num;
        float ans=0;
        while(s<=e){
            long long mid=(s+e)/2;
            if(mid*mid==num){
                return true;

            }
            else if(mid*mid<num){
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return false;
    }
};
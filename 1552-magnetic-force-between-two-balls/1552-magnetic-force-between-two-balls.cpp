class Solution {
private:
    static bool canPlace(int m,int N,vector<int>position,int mid){
        int placed=1;
        int location=position[0];
         for(int i=1;i<=N-1;i++){
            int current_location=position[i];
            if(current_location-location>=mid){
                placed++;
                location=current_location;
                if(placed==m)return true;
            }
         }
         return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int N=position.size();
        int s=0;
        int e=position[N-1]-position[0];
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            bool can_Place=canPlace(m,N,position,mid);   
            if(can_Place){
                ans=mid;
                s=mid+1;
            }else e=mid-1;
            }
            return ans;
    }
};
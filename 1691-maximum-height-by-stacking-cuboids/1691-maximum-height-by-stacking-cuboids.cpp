class Solution {
public:
    
bool canPlace(const vector<int> a, const vector<int> b) {
    return (a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2]);
}
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &row:cuboids){
            sort(row.begin(),row.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        vector<int>dp(n+1,0);
        for(int i=0;i<n;i++){
            dp[i]=cuboids[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(canPlace(cuboids[j],cuboids[i])){
                    int curr_hieght=cuboids[i][2];
                    if(dp[j]+curr_hieght>dp[i]){
                        dp[i]=curr_hieght+dp[j];
                    }
                }
            }
        }
        int maxi=0;
        for(int i:dp){
            maxi=max(i,maxi);

        }
        return maxi;

    }
};
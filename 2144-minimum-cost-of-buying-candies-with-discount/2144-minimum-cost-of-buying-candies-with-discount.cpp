class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        if(cost.size()==0)return 0;
        if(cost.size()==2)return cost[0]+cost[1];
        int sum=0;
        for(int i=0;i<cost.size();i++){
            if(i%3!=2){
            sum+=cost[i];}
        }
        return sum;
    }
};
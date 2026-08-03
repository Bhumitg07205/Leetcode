class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int>set;
        for(int i:nums){
            set.insert(i);
        }
        int largest=1;
        for(auto element :set){
            int parent =element-1;
            if(set.find(parent)==set.end()){
                int next=element+1;
                int cnt=1;
                while(set.find(next)!=set.end()){
                    next++;
                    cnt++;
                }
                if(cnt>largest)largest=cnt;
            }
            
        }
        return largest;

    }
};
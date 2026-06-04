class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        unordered_set<int>s;
        for(int a:nums){
            s.insert(a);
        }
        int largest=1;
        for(auto element:s){
            int parent=element-1;
            if(s.find(parent)==s.end()){
                int next_number=element+1;
                int cnt=1;
                while(s.find(next_number)!=s.end()){
                    next_number++;
                    cnt++;
                }
                if(cnt>largest)largest=cnt;

            }
        }
        return largest;
    }
};
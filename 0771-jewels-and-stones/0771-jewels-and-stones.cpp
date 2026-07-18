class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int>st;
        int count;
        for(char c:jewels){
            st.insert(c-'a');
        }
        for(char c:stones){
            if(st.find(c-'a')!=st.end()){
                count++;
            }

        }
        return count;
    }
};
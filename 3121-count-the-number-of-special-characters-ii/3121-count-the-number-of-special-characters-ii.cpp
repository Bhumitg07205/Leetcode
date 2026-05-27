class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower_map(26,-1);
        vector<int>upper_map(26,-1);
        int i=0;
        for(auto c:word){
            if(islower(c) ){
                lower_map[c-'a']=i;
            }
            else if (isupper(c)) {
                if (upper_map[c - 'A'] == -1) {
                    upper_map[c - 'A'] = i;
                }}
            i++;
        }
        int ans=0;
        for (int i = 0; i < 26; ++i){
        if (lower_map[i] != -1 && upper_map[i] != -1 && lower_map[i] < upper_map[i])++ans;}
        
return ans;
    }
};
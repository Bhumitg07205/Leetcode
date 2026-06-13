class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        for(const string& word:words){
            int wordwt=0;
            for(char c: word){
                wordwt+=weights[c-'a'];
                
            }
            int modv=wordwt%26;
            char a='z'-modv;
            result+=a;
            
        }
        return result;
    }
};
class Solution {
public:
    string processStr(string s) {
        string result;
        for(char c:s){
            switch(c){
                case '*': if (!result.empty())result.pop_back();break;
                case '#': result+=result;break;
                case '%': reverse(result.begin(),result.end());break;
                default: result+=c;break;
            }
        }
        return result;
    }
};
class Solution {
    private:
    static bool compare(const string& a, const string& b){
        return a+b>b+a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str;
        for(auto &c:nums){
            str.push_back(to_string(c));
        }
        sort(str.begin(),str.end(),compare);
        if(str[0]=="0") {return "0";}
        string result;
        for(auto &c:str){
            result+=c;
        }
        return result;
    }
};
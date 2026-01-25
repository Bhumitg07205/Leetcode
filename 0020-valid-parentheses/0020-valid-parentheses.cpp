class Solution {
public:
    bool isValid(string s) {
        stack <char> ch;
        for (auto w:s){
            switch(w){
                case '(': 
                case '[':
                case '{': ch.push(w); break;

                case ')':if(!ch.empty() && ch.top()=='('){
                    ch.pop();} else{return false;}break;
                case ']':if(!ch.empty() && ch.top()=='['){
                    ch.pop();} else{return false;}break;
                case '}':if(!ch.empty() && ch.top()=='{'){
                    ch.pop();} else{return false;}break;

            }

        }
        return ch.empty();
    }
};
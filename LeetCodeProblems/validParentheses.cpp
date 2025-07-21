#include <stack>

bool isValid(string s) {
    if(s.length()%2 != 0) return false;
    std::stack<char> stk;
    for(char c : s){
        if(c == '{' || c == '(' || c == '['){
            stk.push(c);
        } else if (stk.empty()){
            return false;
        } else if( (c == '}' && stk.top() == '{') || (c == ')' && stk.top() == '(') || (c == ']' && stk.top() == '[')){
            stk.pop();
        } else {
            return false;
        }
    }

    return stk.empty();
}
#include <string>

bool isPalindrome(int x) {
    if(x < 0){
        return false;
    }

    std::string number = std::to_string(x);
    size_t len = number.length();
    int i, j;
    if(len%2 == 0){
        i = len/2-1;
        j = len/2;
    } else {
        i = len/2-1;
        j = len/2+1;
    }

    while(i >= 0 && j <= len){
        if(number[i]!=number[j])
            return false;
        i--;
        j++;
    }
    return true;
}

bool isPalindrome1(int x) {
    if(x < 0){
        return false;
    }

    std::string number = std::to_string(x);
    size_t len = number.length();
    
    std::stack<char> stk;
    for(int i = 0; i < len; i++){
        stk.push(number[i]);
    }
    for(int i = 0; i < len; i++){
        if(number[i] != stk.top())
            return false;
        stk.pop();
    }
    return true;
}
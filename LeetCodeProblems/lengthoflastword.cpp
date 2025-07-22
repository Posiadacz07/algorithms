#include <string>

int lengthOfLastWord(std::string s) {
    int result = 0;
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == ' ' && result > 0 ){
            break;
        } else if (s[i] == ' ' && result == 0 ) {
            continue;
        } else {
            result++;
        }
    }
    return result;
}

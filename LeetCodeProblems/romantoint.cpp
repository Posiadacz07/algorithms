#include <string>

int romanToInt(string s) {
        std::unordered_map<char, int> value = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int result = 0;
        for(int i = 0; i < s.length()-1; i++){

            if(i < s.length() - 1 && value(s[i]) < value(s[i+1]) ){
                result += value(s[i+1])-value(s[i]);
                i++;
            } else {
                result += value(s[i]);
            }
        }
        return result;
}
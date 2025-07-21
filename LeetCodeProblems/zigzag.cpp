#include <string>

std::string convert1(std::string s, int numRows) {
    if(s.length() <= numRows || numRows == 1){
        return s;
    }
    
    std::vector<std::vector<char>> str(numRows);
    int idx = 0;
    int count = 1;
    for(int i = 0; i < s.length(); i++){
        str[idx].push_back(s[i]);
        
        if(idx == 0){
            count = 1;
        } else if (idx == numRows - 1) {
            count = -1;
        }
        idx += count;
    }

    std::string result;
    for (const auto& row : str) {
        for (char c : row) {
            result += c;
        }
    }
    return result;
}

std::string convert(std::string s, int numRows) {
    if(s.length() <= numRows || numRows == 1){
        return s;
    }
    
    std::vector<std::string> str(numRows, "");
    int idx = 0;
    int count = 1;
    for(int i = 0; i < s.length(); i++){
        str[idx] += s[i];
        
        if(idx == 0){
            count = 1;
        } else if (idx == numRows - 1) {
            count = -1;
        }
        idx += count;
    }

    std::string result;
    for (const auto& row : str) {
        result += row;
    }
    return result;
}
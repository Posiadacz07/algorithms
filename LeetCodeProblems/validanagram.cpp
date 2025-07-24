#include <string> 

bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> frequencyMap;
    for(char c : s){
        frequencyMap[c] += 1;
    }
    for(char c : t){
        frequencyMap[c] -= 1;
    }
    for(char c : s){
        if (frequencyMap[c] != 0) {
            return false;
        }
    }
    for(char c : t){
        if (frequencyMap[c] != 0){
            return false;
        }
    }
    return true;
}

bool isAnagram(std::string s, std::string t) {
    if(s.length() != t.length()){
        return false;
    }

    std::unordered_map<char, int> frequencyMap;
    for(char c : s){
        frequencyMap[c] += 1;
    }
    for(char c : t){
        if(frequencyMap.find(c) == frequencyMap.end())
            return false;
        frequencyMap[c] -= 1;
    }
    for(char c : s){
        if (frequencyMap[c] != 0) {
            return false;
        }
    }
    return true;
}
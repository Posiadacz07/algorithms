#include <string>

int firstUniqChar(std::string s) {
    int freq[26] = {0};

    for (char c : s) {
        freq[c - 'a']++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int firstUniqChar(string s) {
    std::unordered_map<char, int> characterFrequencyMap;
    for(char c : s){
        characterFrequencyMap[c] += 1;
    }
    for(int i = 0; i < s.length(); i++){
        if(characterFrequencyMap[s[i]] == 1){
            return i;
        }
    }
    return -1;
}

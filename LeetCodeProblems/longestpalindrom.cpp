#include <string>

// O(n^2)
std::string longestPalindrome(std::string s) {
    int start = 0;
    int end = 0;

    // First loop
    for(int i = 0; i < s.length(); i++){
        int odd = checkPalindrom(s, i, i);
        int even = checkPalindrom(s, i, i + 1);
        int max_len = std::max(odd, even);

        if (max_len > end - start){
            // For even palindroms, as we added 1, we need to substruct it
            // For odd palindroms it doesn't change anything
            start = i - (max_len - 1) / 2;
            end = i + max_len / 2;
        }
    }
    // substr end position is not included into final string
    return s.substr(start, end - start + 1);
}

int checkPalindrom(std::string s, int left, int right){
    // Second loop
    while(right <= s.length() && left >= 0 && s[left] == s[right]){
        left--;
        right++;
    }
    return right - left -1;
}
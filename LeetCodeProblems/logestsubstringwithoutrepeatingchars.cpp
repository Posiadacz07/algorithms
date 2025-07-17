#include <unordered_set>
#include <string>

int lengthOfLongestSubstring(std::string s) {
    int left = 0;
    int maxLength = 0;
    // You can use both set and unordered_set but it will change time of finding elelment
    // And at the end time complexity (with set it will be O(log(n)), with unordered_set O(1))
    std::unordered_set<char> charSet;

    for (int right = 0; right < s.length(); right++) {
        while (charSet.find(s[right]) != charSet.end()) {
            // When checking if char is in set we are removing all elements 
            // from left up to our cuurent one
            charSet.erase(s[left]);
            left++;
        }

        charSet.insert(s[right]);
        // Every time we are moving L and R pointers we are calculating max lenght
        // to store the biggest substring we had up to this point
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;        
}
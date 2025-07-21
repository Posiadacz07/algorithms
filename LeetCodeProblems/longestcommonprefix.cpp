#include <string>
#include <vector>
#include <algorithms>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if(strs.empty()) return "";
    std::string prefix = "";
    std::sort(strs.begin(), strs.end());
    std::string first = strs[0], last = strs.back();
    for(int i = 0; i < first.length(); i++){
        if(i < last.length() && first[i] == last[i]){
            prefix += first[i];
        } else {
            break;
        }
    }
    return prefix;
}
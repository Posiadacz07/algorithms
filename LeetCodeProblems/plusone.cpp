#include <vector>

std::vector<int> plusOnestd::(vector<int>& digits) {
    int overflow = 1;
    int i = digits.size() - 1 ;
    while(overflow != 0 && i >= 0){
        int sum = digits[i] + overflow;
        if (sum == 10) {
            digits[i] = 0;
            overflow = 1;
            i--;
        } else {
            overflow = 0;
            digits[i] = sum;
        }
    }
    if (overflow > 0) {
        digits.insert(digits.begin(), overflow);
    }
    return digits;
}
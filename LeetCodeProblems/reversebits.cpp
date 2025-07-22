#include <string>
#include <bitset>
#include <algorithms>

int reverseBits(int n) {
    std::string binaryNumber = std::bitset<32>(n).to_string();
    reverse(binaryNumber.begin(), binaryNumber.end());
    uint32_t result = std::bitset<32>(binaryNumber).to_ulong();
    return result;
}
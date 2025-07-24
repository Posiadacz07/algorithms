#include <vector>
#include <algorithms>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int max = 0;
    
    auto first = std::find(nums.begin(), nums.end(), 1);
    while(first != nums.end()){
        auto end = std::find(first, nums.end(), 0);
        int count = std::distance(first, end);
        if (count > max){
            max = count;
        }
        first = std::find(end, nums.end(),1);
    }
    return max;
}
#include <vector>

// Use 2 pointers solution, write elements that needs to stay to new index position
// You can be sure that you don't overrive any importatn element
void moveZeroes(std::vector<int>& nums) {
    int index = 0;
    int size = nums.size();
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            nums[index] = nums[i];
            index++;
        }
    }
    for(int i = index; i < size; i++){
        nums[i] = 0;
    }
}
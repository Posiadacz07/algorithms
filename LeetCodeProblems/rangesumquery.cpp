#include <vector>

class NumArray {
public:
// While initializing calculate sums of n elements up for 0 to n
    NumArray(std::vector<int>& nums) : numsPreSum(nums) {
        for(int i = 1; i < numsPreSum.size(); i++){
            numsPreSum[i] += numsPreSum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return numsPreSum[right];
        }
        return numsPreSum[right] - numsPreSum[left-1];
    }
private: 
    std::vector<int>&  numsPreSum;
};
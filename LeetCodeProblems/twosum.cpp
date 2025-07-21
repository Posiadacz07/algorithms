#include <vector>
#include <unordered_map>

// Example input and output
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

// You cna use vector instead of unordered_map but then the same algorithm will have
// O(n^2) time complexity
// WHen suing unordered_map (hash map) finding element is in const time
// which makes whole algorint O(n) time complexity
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> pointit;
    for(int i = 0; i < nums.size(); i++){
        int diff = target - nums[i]; 
        if(pointit.find(diff) != pointit.end()){
            return {pointit[diff], i};
        }
        else {
            pointit[nums[i]] = i;
        }
    }
    return {};
}
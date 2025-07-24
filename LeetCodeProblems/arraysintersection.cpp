#include <vector>
#include <unordered_map>

// Find uniqe elements that are intersection of two vectors
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> frequencyMap(nums1.begin(), nums1.end());

    std::vector<int> result;
    for(int i : nums2){
        if(frequencyMap.find(i) != frequencyMap.end()){
            result.push_back(i);
            frequencyMap.erase(i);
        }
    }
    return result;
}
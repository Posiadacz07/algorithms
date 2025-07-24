#inluce <vector>
#inlucde <unordered_map>

int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> frequencyMap;
    for(int i : nums){
        frequencyMap[i] += 1;
    }
    // Check which element has frequency over half of the number of elements
    for(auto x : frequencyMap){
        if(x.second > nums.size()/2){
            return x.first;
        }
    }
    return 0;
}
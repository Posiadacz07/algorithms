#include <vector>
#include <algorithms>

int maxArea(std::vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int result = 0;
    while (left < right){
        if(height[left] > height[right]){
            int area = (right - left) * height[right];
            right--;
            result = max(area, result);
        } else {
            int area = (right - left) * height[left];
            left++;
            result = max(area, result);
        }
    }
    return result;
}
#include <vecotr>
#include <sort>


// The simples solution is to combine vectors, sort them and calculate median form agregated vector
// Time complexity is O(n*log(n)) because sorting algorithm has this time complexity
double findMedianSortedArrays1(std::vector<int>& nums1, std::vector<int>& nums2) {
    double median = 0;
    std::vector<int> agregated = nums1;
    agregated.insert(agregated.end(), nums2.begin(), nums2.end());
    std::sort(agregated.begin(), agregated.end());
    if(agregated.size()%2 == 1)
        median = agregated[agregated.size()/2];
    else
        median = (agregated[agregated.size()/2-1] + agregated[agregated.size()/2])/2.0;
    return median;
}

// This solution only goes though (n+m)/2 elements so this is it's time complexity
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    double median = 0.0;
    int middle_point = (nums1.size() + nums2.size())/2;
    int i = 0, j = 0;
    // num1 stores current number to be median
    // num2 stores number before num1 to calculate median when there is right number all elements
    int num1 = 0, num2 = 0;

    for(int count = 0; count < middle_point + 1; count++){
        num2 = num1;
        // When both vectors still have elements left
        if (i < nums1.size() && j < nums2.size()){
            if(nums1[i] > nums2[j]){
                num1 = nums2[j];
                j++;
            } else {
                num1 = nums1[i];
                i++;
            }
        // When first vector has elements left
        } else if (i < nums1.size()){
            num1 = nums1[i];
            i++;
        // When second vector has elements left
        } else {
            num1 = nums2[j];
            j++;
        }
    }

    if ((nums1.size() + nums2.size()) % 2 == 1){
        median = num1;
    } else {
        median = (num1 + num2) / 2.0;
    }
    return median;
}
